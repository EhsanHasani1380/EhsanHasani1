#include <iostream>
#include <filesystem>

namespace fs = std::filesystem ; 

using namespace std ;

int main(int argc, char *argv[])
{
   std::string rootDir = "C:\\";
   std::vector<std::string> files;
   std::error_code ec ; 
   bool flagIfItIncrease  ; 

   int i = 0 ;
                    
   fs::recursive_directory_iterator it (rootDir,fs::directory_options::skip_permission_denied) ;
   fs::recursive_directory_iterator  end ;
    while (it != end) 
    {
        flagIfItIncrease = true ; 
        rootDir = it->path().string();

        if (!is_directory(it->path() , ec )) 
        {   
            files.push_back(it->path().string());
                        
        }

        if (ec)
        {
            ++it ;
            flagIfItIncrease = false ;
            i++ ;  
        }
        
        if (flagIfItIncrease == true)
        {
            ++it ;
        }
              
        
    }

        
     for (std::string const& filePath : files) 
            {
                
                std::cout << filePath << std::endl;
                 
            }


          cout << "\n\ni = " << i ;  
            return 0 ;

 }

    