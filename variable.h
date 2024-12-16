#include <iostream>
#include <fstream> // Only can used create file but if file path not exists it will faild for action
#include <iomanip> // IO format setup
#include <filesystem> // Create file Path if doesn't exist,but it can't write the files  
#include <ctime> // system time
#include <windows.h> //Windows API
//#include <unistd.h> //Unix and Linux API

//std::string log_File_Path = "file_log.log";
std::ifstream in;
std::ofstream out;
std::ifstream in_a;
std::ofstream out_a;

time_t log_wrote_time = time(0); //Get the time from now
struct tm *ltm = localtime(&log_wrote_time); //Get the structure from time of local

std::string Log_Directory = "./log/";
std::string Log_file = Log_Directory + "pswd.log";
std::string pswd_save_Dir = "./pswd/";
std::string pswd_save = pswd_save_Dir + "password.txt";

std::string str_password = ""; //saved password
std::string check_str_password = ""; //check password
int times_for_locked = 3; //3 times for opportunity and for try to lock the secure-lock 
char option; // CLI of option 
/*
 Note:
 "return 0" is normal status
 "return 1" is error status
*/ 