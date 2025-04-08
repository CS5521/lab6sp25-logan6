3750 #include "types.h"
3751 #include "x86.h"
3752 #include "defs.h"
3753 #include "date.h"
3754 #include "param.h"
3755 #include "memlayout.h"
3756 #include "mmu.h"
3757 #include "proc.h"
3758 
3759 static int numForks;
3760 
3761 int
3762 sys_fork(void)
3763 {
3764   numForks++;
3765   return fork();
3766 }
3767 
3768 int
3769 sys_exit(void)
3770 {
3771   exit();
3772   return 0;  // not reached
3773 }
3774 
3775 int
3776 sys_wait(void)
3777 {
3778   return wait();
3779 }
3780 
3781 int
3782 sys_kill(void)
3783 {
3784   int pid;
3785 
3786   if(argint(0, &pid) < 0)
3787     return -1;
3788   return kill(pid);
3789 }
3790 
3791 int
3792 sys_getpid(void)
3793 {
3794   return myproc()->pid;
3795 }
3796 
3797 
3798 
3799 
3800 int
3801 sys_sbrk(void)
3802 {
3803   int addr;
3804   int n;
3805 
3806   if(argint(0, &n) < 0)
3807     return -1;
3808   addr = myproc()->sz;
3809   if(growproc(n) < 0)
3810     return -1;
3811   return addr;
3812 }
3813 
3814 int
3815 sys_sleep(void)
3816 {
3817   int n;
3818   uint ticks0;
3819 
3820   if(argint(0, &n) < 0)
3821     return -1;
3822   acquire(&tickslock);
3823   ticks0 = ticks;
3824   while(ticks - ticks0 < n){
3825     if(myproc()->killed){
3826       release(&tickslock);
3827       return -1;
3828     }
3829     sleep(&ticks, &tickslock);
3830   }
3831   release(&tickslock);
3832   return 0;
3833 }
3834 
3835 // return how many clock tick interrupts have occurred
3836 // since start.
3837 int
3838 sys_uptime(void)
3839 {
3840   uint xticks;
3841 
3842   acquire(&tickslock);
3843   xticks = ticks;
3844   release(&tickslock);
3845   return xticks;
3846 }
3847 
3848 
3849 
3850 int
3851 sys_hw(void)
3852 {
3853   cprintf("hello world!\n");
3854   return 0;
3855 }
3856 
3857 int
3858 sys_fkc(void)
3859 {
3860   return numForks;
3861 }
3862 
3863 
3864 
3865 
3866 
3867 
3868 
3869 
3870 
3871 
3872 
3873 
3874 
3875 
3876 
3877 
3878 
3879 
3880 
3881 
3882 
3883 
3884 
3885 
3886 
3887 
3888 
3889 
3890 
3891 
3892 
3893 
3894 
3895 
3896 
3897 
3898 
3899 
