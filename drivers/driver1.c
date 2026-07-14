#include<linux/module.h>
#include<linux/init.h>

int my_init(void){
    printk("hello kernal\n");
    return 0;
}

void my_exit(void){
    printk("good bye kernal\n");
}

module_init(my_init);
module_init(my_exit);


MODULE_LICENSE("GPL");
