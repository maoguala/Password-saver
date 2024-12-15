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

    return 0;
}