#include "variable.h" //The customize function by self, so used "" for customize-function

int main()
{
    if(!std::filesystem::exists(Log_Directory))
    {   
        //std::filesystem::create_directories(Log_Directory);  // create the directory
        if(std::filesystem::create_directories(Log_Directory))
        {
            //std::cout  << "Created!";
        }
        else
        {
            std::cerr << "FILE WAS FAILD TO CREAT, PLEASE TYR AGAING !\n";
            return 1;   
        }
    }

    in.open(Log_file); //start the file first
    if(!out.is_open()) //if the file which called "Log_file" not start, the code will create for the file which called "pswd.log"
    { 
        out.open(Log_file, std::ios::app);
        out << "[ " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " ]" << " Empty Log was created!" << std::endl; //Wrote in pswd.log
    }
    in.close();
    out.close();

    if(!std::filesystem::exists(pswd_save_Dir))
    {   
         // create the directory
        if(std::filesystem::create_directories(pswd_save_Dir))
        {
            //std::cout  << "Created!";
        }
        else
        {
            std::cerr << "FILE WAS FAILD TO CREAT, PLEASE TYR AGAING !\n";
            return 1;   
        }
    }

    in_a.open(pswd_save); //start the file first
    if(!out_a.is_open()) //if the file which called "Log_file" not start, the code will create for the file which called "pswd.log"
    { 
        out_a.open(pswd_save, std::ios::out);   
        out.open(Log_file,std::ios::app);
        out << "[ " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " ]" << " Empty password recorder was created!" << std::endl; //Wrote in password.txt
    }
    in_a.close();
    out_a.close();
    in.close();
    out.close();

    //while loop start way!
    while(true)
    {
        //CLI initialize
        std::cout << "---------------------------------" << std::endl;
        std::cout << "             Options             " << std::endl;
        std::cout << "---------------------------------" << std::endl;
        std::cout << "(1). Exit" << std::endl;
        std::cout << "(2). Save the password " << std::endl;  //save the password and it will write "log" for record password wrote
        std::cout << "(3). Test unlock current password" << std::endl; //Test and it will to save "Success-log" and "Faild-log"
        std::cout << "---------------------------------" << std::endl;
        std::cout << "[Enter]: ";
        //Enter select
        std::cin >> option;
        
        //start to judge
        if(option == '1')
        {
            out.open(Log_file, std::ios::app);
            out << "[ " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " ] " << "The program was ended" << std::endl; //Wrote into pswd.log
            out.close();
            exit(1); //End the program
        }
        else if(option == '2')
        {
            system("cls"); // Windows API
            std::cout << "[Enter the new password]: ";
            std::cin >> str_password;
            out_a.open(pswd_save, std::ios::out);
            out_a << str_password; // write in password
            out_a.close();
            out.open(Log_file, std::ios::app);
            out << "[ " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " ] " << "New password created: " << str_password << std::endl; //Wrote into pswd.log
            out.close();
            system("cls");
        }
        else if(option == '3')
        {
            system("cls");
            std::cout << "[Enter the current password]: ";
            std::cin >> check_str_password;
            in_a.open(pswd_save, std::ios::in);
            in_a >> str_password;
            in_a.close();
            
            if(check_str_password == str_password)
            {
                std::cout << "Successed!" << std::endl;
                out.open(Log_file, std::ios::app);
                out << "[ " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " ] " << "Successed for Unlock by password: " << check_str_password << std::endl; //Wrote into pswd.log
                out.close();
                system("cls");
            }
            else
            {   
                out.open(Log_file, std::ios::app);
                out << "[ " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " ] " << "Failed for Unlock by password: " << check_str_password << std::endl; //Wrote into pswd.log
                out.close();
                while(true)
                {
                    if(times_for_locked == 0){
                        out.open(Log_file, std::ios::app);
                        out << "[ " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " ] " << "The program was ended by FATAL ERROR!" << std::endl; //Wrote into pswd.log
                        out.close();
                        exit(1);
                    }
                    if(times_for_locked == 1){
                        std::cout << "WARNING! THE LAST CHANCE FOR ENTER PASSWORD, IF ENTER WRONG PASSWORD AGAIN, THE PROGRAM WILL CLOSED!" << std::endl;
                        Sleep(3000);
                    }
                    system("cls");
                    std::cout << "FAILED! WRONG PASSWORD!" << std::endl << "PLEASE ENTER IN AGAIN: ";
                    std::cin >> check_str_password;
                    system("cls");
                    if(check_str_password == str_password) 
                    {
                        break;
                    }
                    times_for_locked = times_for_locked - 1; //reduse the times with 1
                    out.open(Log_file, std::ios::app);
                    out << "[ " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " ] " << "Failed for Unlock by password: " << check_str_password << std::endl; //Wrote into pswd.log
                    out.close();    
                }
                std::cout << "Successed!" << std::endl;
                out.open(Log_file, std::ios::app);
                out << "[ " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << " ] " << "Successed for Unlock by password: " << check_str_password << std::endl; //Wrote into pswd.log
                out.close();
                system("cls");                 
            }
            times_for_locked = 3; //regive the value
        }
    }
    
    return 0;
}