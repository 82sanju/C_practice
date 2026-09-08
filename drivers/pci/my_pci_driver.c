#include <linux/module.h>
#include <linux/pci.h>
#include <linux/io.h>
#define __KERNEL__
#define MODULE

#define DRIVER_NAME "my_pci_driver"

// mock Vendor ID & Device ID
#define MY_VENDOR_ID 0x1234
#define MY_DEVICE_ID 0x5678
static void __iomem *mmio_base;

//Called when device is found

static int my_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
    int ret;

    pr_info("PCI device detected\n");

    ret = pci_enable_device(pdev);
    if (ret) {
        pr_err("Failed to enable PCI device\n");
        return ret;
    }

    // Request BAR region -BAR0
    ret = pci_request_region(pdev, 0, DRIVER_NAME);
    if (ret) {
        pr_err("Failed to request BAR\n");
        pci_disable_device(pdev);
        return ret;
    }

    //Map BAR0 (MMIO)
    mmio_base = pci_iomap(pdev, 0, 0);
    if (!mmio_base) {
        pr_err("Failed to map MMIO\n");
        pci_release_region(pdev, 0);
        pci_disable_device(pdev);
        return -ENOMEM;
    }

    pr_info("MMIO mapped successfully\n");

    //Read register at offset 0
    u32 val = readl(mmio_base + 0x0);
    pr_info("Register[0x0] = 0x%x\n", val);

    return 0;
}

static void my_remove(struct pci_dev *pdev)
{
    pr_info("Removing PCI device\n");

    pci_iounmap(pdev, mmio_base);
    pci_release_region(pdev, 0);
    pci_disable_device(pdev);
}

// Device ID tabl
static const struct pci_device_id my_pci_ids[] = {
    { PCI_DEVICE(MY_VENDOR_ID, MY_DEVICE_ID) },
    { 0, }
};
MODULE_DEVICE_TABLE(pci, my_pci_ids);

//PCI driver structure
static struct pci_driver my_driver = {
    .name = DRIVER_NAME,
    .id_table = my_pci_ids,
    .probe = my_probe,
    .remove = my_remove,
};

/* Register driver */
module_pci_driver(my_driver);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("You");
MODULE_DESCRIPTION("Minimal PCI Driver");