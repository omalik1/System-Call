Part C: Kernel Module

Three files are attached for this part; mytime.c, userMyTime.c, Makefile and the README.txt.

mytime.c has kernel level module related code consisting of the following functions:
my_f() - is a struct of type file_operations which has my_dev_read() assigned to its .read	  
my_init() - is the initialization of the module where we register/load the device
my_dev_read() - is the getting the two times; getnsTimeofDay() and current_kernel_time() 
register_device() - is where the char device is registered and major number is given to the device
unregister_device() - unregisters the char device
my_exit() - is where the char device is unregistered/unloaded

userMyTime.c is the code provided. It has chunk of new code that does error checking 

When 'make' is entered for some reason due to compatibility the code doesn't compile. Tried on VM as well as Ubuntu interface but failed to have it working. Have attached the screenshots of the messages that were shown on both machines.

As far as my code doesn't compile and I can't run it I believe -1 in the initialization will fail toregister the module because we are returning -1 which may over ride the major device number.

To compile:

make 
sudo rmmod mytime
sudo insmod mytime.ko
dmesg
sudo mknod /dev/mytime.c c <major number> 0
gcc userMyTime
./a.out
sudo rmmod mytime
