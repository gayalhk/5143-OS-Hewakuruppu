//Gayal Hewakuruppu 
//Michael Tull
//Program 1 - CMPS 5143 Advanced Operating systems

#include<bits/stdc++.h>
#include<iostream>
#include <cstdio>
#include <sched.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h> 
#include <signal.h>  
#include <iostream>
#include <vector>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include<dirent.h>
#include <string>
#include <memory>
#include<algorithm>
#include <functional>
#include <utmp.h>
#include <err.h>
#define NAME_WIDTH  8
#ifdef WINDOWS
#define GetCurrentDir _getcwd
#define GetCurrentDir getcwd
#endif

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;
inline string& trim(string& s, const char* t = " \t")
{
    s.erase(s.find_last_not_of(t) + 1);
    s.erase(0, s.find_first_not_of(t));
    return s;
}

struct malloc_deleter
{
    template <class T>
    void operator()(T* p) { std::free(p); }
};

typedef std::unique_ptr<char, malloc_deleter> cstring_uptr;


 

int main(int argc, char* argv[])
{
  cout <<"\n\t================================================\n\n";
  cout <<"\t      Shell Project - Gayal & Michael      \n\n";
  cout <<"\t================================================\n\n\n";

  while ( true )
    {
      // Show prompt.
      cout << get_current_dir_name () << "$ " ;
      char command[128];
      vector<string> his;
      char extension[10],cmd[50];
      cin.getline( command, 128 );
      vector<char*> args;
      char* prog = strtok( command, " " );
      char* tmp = prog;
      while ( tmp != NULL )
	{
	  args.push_back( tmp );
	  tmp = strtok( NULL, " " );
	}
      
      char** argv = new char*[args.size()+1];
      cout << argv[0];
   
   	/////////////////////////////////////////////////////////////////////
	
       else if(strcmp(command, "pwd") == 0) {
         
          std::string GetCurrentWorkingDir( void ) {
          char buff[FILENAME_MAX];
		  GetCurrentDir( buff, FILENAME_MAX );
		  std::string current_working_dir(buff);
		  return current_working_dir;
		  cout << GetCurrentWorkingDir() << std::endl;
      }
   
    /////////////////////////////////////////////////////////////////////
	
       else if(strcmp(command, "mv") == 0) {
         
          char src[50],dest[50],cmd[100];
		  cout<<"\nEnter full path of file to be moved : ";
		  gets(src);
		  cout<<"Enter full path where file to be moved : ";
		  gets(dest);
		  strcpy(cmd,"mv ");
		  strcat(cmd,src);
		  strcat(cmd," ");
		  strcat(cmd,dest);
		  system(cmd);
		  return 0;
      }
	  
	/////////////////////////////////////////////////////////////////////
	
       else if(strcmp(command, "less") == 0) {
         
          template <typename A, typename B, 
		  typename U = std::less<int> > 
		
          bool f(A a, B b, U u = U()) 
          { 
	         return u(a, b); 
           } 
		  
		  int X = 1, Y = 2; 
	      cout << std::boolalpha; 
	      cout << f(X, Y) << '\n'; 
	      X = 2, Y = -1; 
	      cout << f(X, Y) << '\n'; 

	      return 0; 
      }
     
	    
   /////////////////////////////////////////////////////////////////////
   
      if(strcmp(command, "cp") == 0){
         int read_fd;
         int write_fd;
         struct stat stat_buf;
         off_t offset = 0;
        
         read_fd = open (argv[1], O_RDONLY);
         fstat (read_fd, &stat_buf);
         write_fd = open (argv[2], O_WRONLY | O_CREAT, stat_buf.st_mode);
         sendfile (write_fd, read_fd, &offset, stat_buf.st_size);
         close (read_fd);
         close (write_fd);
         his.push_back(command);
      }
	  
	/////////////////////////////////////////////////////////////////////
	
       else if(strcmp(command, "rm") == 0) {
         
          cout<<"\nENTER EXTENSION OF FILES : ";
          cin>>extension;
          strcpy(command,"rm *.");
          strcat(command,extension);
          system(command);
          his.push_back(command);
      }
	 
	/////////////////////////////////////////////////////////////////////
	
      else if(strcmp(command, "mkdir") == 0) {
            int check;
           char dirname[50];
           cin >> dirname;
           check = mkdir(dirname, 0777);
           //checking if directory is created
           if (!check)
              cout << "Directory created.\n";
           else {
              cout << "Unable to create directory\n";
              exit(1);
           }
           system("dir/p");
           his.push_back(command);
      }

    ////////////////////////////////////////////////////////////
	
      if(strcmp(command, "sort") == 0) {
          int arr[50];
          int num, i;
          cout << "\nEnter total length of numbers: ";
          cin >> num;
          cout << "\nEnter numbers to sort: ";
          for(i = 0; i < num; i++) {
              cin >> arr[i];
          }
          std::vector<int> myvector (arr, arr+num);             

          std::sort (myvector.begin(), myvector.begin()+4);        
        
          std::sort (myvector.begin()+4, myvector.end(), myfunction); 
        
          std::sort (myvector.begin(), myvector.end(), myobject);    
        
          std::cout << "After sorting: ";
          for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
            std::cout << ' ' << *it;
          std::cout << '\n';
          his.push_back(command);
          
      } 
      
        FILE *f = NULL;
        std::string wccmd;
        std::string filename("main.cpp");   // keep appropriate file name
        int n = 0;
        std::string file;
		
	//////////////////////////////////////////////////////////////////////////////
		
        if(strcmp(command, "wc") == 0) {
            wccmd = "wc -l " + filename;
            f = popen(wccmd.c_str(), "r");
            fscanf(f, "%d", &n);
            pclose(f);
            std::cout << "Number of lines: " << n << '\n';
            his.push_back(command);   
        } 
		
	/////////////////////////////////////////////////////////////////////
	
       else if(strcmp(command, "cat") == 0) {
         
          using FilePtr = std::unique_ptr<FILE, decltype(&::pclose)>;
		  std::string cmd("/bin/cat ");
		  cmd.append(path);

		  FilePtr ls(::popen(cmd.c_str(), "r"), ::pclose);
	      if (ls == nullptr)
			return std::string();

		  std::vector<char> buf(1024);
		  std::string ret;
		  while (::fgets(buf.data(), buf.size(), ls.get()))
			ret.append(buf.data());

		  return ret;
      }
   
    
    /////////////////////////////////////////////////////////////////////
	
        if(strcmp(command,"grep") == 0) {
            char fn[10], pat[10], temp[200];
            FILE *fp;
            cout << "\n Enter file name : ";
            cin >> fn;
            cout << "\nEnter the pattern: ";
            cin >> pat;
            fp = fopen(fn, "r");
            while (!feof(fp))
            {
                fgets(temp, sizeof(fp), fp);
                if (strcmp(temp, pat))
                   cout << temp;
            }
            fclose(fp);
            his.push_back(command);
        }

    //////////////////////////////////////////////////////////////////////////////
		
        if(strcmp(command, "chmod") == 0) {
            int result = _chmod(path, (mode & MS_MODE_MASK));

             if (result != 0){
				result = errno;
                  }

			return (result);
		else
            static inline int my_chmod(const char * path, mode_t mode)
		}
    int result = chmod(path, mode);

    if (result != 0)
    {
        result = errno;
    }

    return (result);  
        } 
				
		
    //////////////////////////////////////////////////////////////////////
	
        if(strcmp(command, "head") == 0) {
            ifstream file; 
        	char word[250];
        	
        	file.open("characters.txt");     //set file name here
        	if (!file.is_open())
        	{
        		exit(EXIT_FAILURE);
        	}
        	
        	
        	int counter = 0;
        	while (counter < 10 && file.good() )
        	{
        		file.getline(word, 250);
        		counter++;
        		cout << word << endl;
        	}
        	
        	if (counter < 10)
        	{
        		cout << "\nThe entire file was read.\n";
        	}
        	
        	cout << "We read " << counter << " lines today.\n";
        		
        	cout << "Press enter to exit.\n";
        	cin.get(word, 250);
          his.push_back(command);
        }

    //////////////////////////////////////////////////////////////////////////////
		
        if(strcmp(command, "tail") == 0) {
            void tail(FILE* in, int n) { 
				int count = 0; 
				unsigned long long pos; 
				char str[2*SIZE]; 

			if (fseek(in, 0, SEEK_END)) 
				perror("fseek() failed"); 
			
			else{ 
				pos = ftell(in); 
				while (pos) { 
					if (!fseek(in, --pos, SEEK_SET)) { 
						if (fgetc(in) == '\n') 
							if (count++ == n) 
								break; } 
					else
						perror("fseek() failed"); } 
			printf("Printing last %d lines -\n", n); 
			while (fgets(str, sizeof(str), in)) 
			printf("%s", str); } 
			printf("\n\n"); }    
        } 
				
		
	///////////////////////////////////////////////////////////////////////////
        
      for ( int k = 0; k < args.size(); k++ )
	argv[k] = args[k];
      
      argv[args.size()] = NULL;
      
      if ( strcmp( command, "exit" ) == 0 )
	{
	  return 0;
	}
      else
	{
	  if (!strcmp (prog, "cd"))
	    {
	      if (argv[1] == NULL)
		{
		  chdir ("/");
		}
	      else
		{
		  chdir (argv[1]);
		}
	      perror (command);
        his.push_back(command);
	    }
	  else
	    {
	      pid_t kidpid = fork();

	      if (kidpid < 0)
		{
		  perror( "Internal error: cannot fork." );
		  return -1;
		}
	      else if (kidpid == 0)
		{
		  execvp (prog, argv);
		  perror( command );
		  return -1;
		}
	      else
		{
		  if ( waitpid( kidpid, 0, 0 ) < 0 )
		    {
		      perror( "Internal error: cannot wait for child." );
		      return -1;
		    }
		}
	    }
	}
    }
  
  return 0;
}
