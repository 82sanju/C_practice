#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "hello_char"
#define BUF_SIZE 1024

static int major;
static char device_buffer[BUF_SIZE];
static int buffer_size = 0;

/* 🔹 Open */
static int dev_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");
    return 0;
}

/* 🔹 Read */
static ssize_t dev_read(struct file *file, char __user *user_buffer,
                        size_t len, loff_t *offset)
{
    int bytes_to_read;

    if (*offset >= buffer_size)
        return 0;

    bytes_to_read = min((int)len, buffer_size - (int)*offset);

    if (copy_to_user(user_buffer, device_buffer + *offset, bytes_to_read))
        return -EFAULT;

    *offset += bytes_to_read;

    printk(KERN_INFO "Read %d bytes\n", bytes_to_read);
    return bytes_to_read;
}

/* 🔹 Write */
static ssize_t dev_write(struct file *file, const char __user *user_buffer,
                         size_t len, loff_t *offset)
{
    int bytes_to_write = min((int)len, BUF_SIZE);

    if (copy_from_user(device_buffer, user_buffer, bytes_to_write))
        return -EFAULT;

    buffer_size = bytes_to_write;

    printk(KERN_INFO "Written %d bytes\n", bytes_to_write);
    return bytes_to_write;
}

/* 🔹 Close */
static int dev_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");
    return 0;
}

/* 🔹 File operations */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = dev_open,
    .read = dev_read,
    .write = dev_write,
    .release = dev_release,
};

/* 🔹 Init */
static int __init hello_init(void)
{
    major = register_chrdev(0, DEVICE_NAME, &fops);

    if (major < 0) {
        printk(KERN_ALERT "Failed to register device\n");
        return major;
    }

    printk(KERN_INFO "Registered character driver with major number %d\n", major);
    return 0;
}

/* 🔹 Exit */
static void __exit hello_exit(void)
{
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Character driver unregistered\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("You");
MODULE_DESCRIPTION("Simple Hello Character Driver");