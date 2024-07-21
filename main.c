void my_thread_function(void);


int main()
{
  HANDLE thread1 = start_listening(my_thread_function); // create a new thread named thread1 to be executed seperately from the main program. // use it if you nead it wherever you want

 





return 0;

  WaitForSingleObject(thread1, INFINITE); // wait INFINITE milliseconds for thread1 to finish(you can put a number instead of INFINITE like 1000, which in this case thread1 will be killed in 1000 milliseconds). better not to reach this line cuz the main program may stuck here a while
}

void my_thread_function(void){

  //put anything that you want to run simultaneously with the main code in here
  //it will run only once so you should restrict it to a while true loop or frequently create a thread with this function's name as its parameter


}
