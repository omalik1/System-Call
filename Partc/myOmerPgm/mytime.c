#include <linux/init.h>
#include <linux/module.h>

#define SUCCESS 0

MODULE_LICENSE("GPL");
MODULE_AUTHOR("OMER MALIK");

static int device_mj_num = 0;
static const char dev_name[] = "Get-Time";
static const char myT[400];
static const ssize_t time_string_size = sizeof(myT); 

/* Helps in carrying out the registered devices to perform a task */
static struct file_operations my_f
{
	.read = my_dev_read
};

/* To load a linux driver */
static int my_init(void)
{
	register_device();	
	return 0;
}

/* Gets the times and returns them in user level interface */
static ssize_t my_dev_read( struct file *file_ptr,
			    char __user *user_buffer,
			    size_t count,
			    loff_t *position)
{
	struct timespec time1 = current_kernel_time();
	struct timespec time2;
	getnstimeofday(&time2);
	sprintf(myT, "current_kernel_time: %ld\n getnstimeofday: %ld\n",time1.tv_nsec, time2.tv_nsec);
	printl(KERN_INFO, "%s", myT);
	copy_to_user(user_buffer,myT,strlen(myT)+1); // to copy from kernel to user space
	return strlen(myT);

}


/* Registering a device */
static int register_device(void)
{
	int register_num = 0;
	printk(KERN_NOTICE "Get-Time: register_device() is called.");
	register_num = register_chrdev(0, dev_name, &my_f);
	if(register_num < 0)
	{
		printk(KERN_WARNING "Get-Time: Failed to register with error %i", register_num);
	}
	device_mj_num = register_num;
	printk(KERN_NOTICE "Get-Time: registered device major number is %i", device_mj_num);
	return SUCCESS;
}

/* Unregistering a device */
void unregister_device(void)
{
	printk(KERN_NOTICE "Get-Time: unregister_device() is called");
	if(device_mj_num != 0)
	{
		unregister_chrdev(device_mj_num, dev_name);
	}
}
/* To unload a linux driver */
static void my_exit(void)
{
	unregister_device();
	return;
}
