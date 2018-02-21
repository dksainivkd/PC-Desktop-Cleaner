#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include<bits/stdc++.h>
#include <fcntl.h>
#include<sys/stat.h>
#include <fstream>

using namespace std;

void move_file(string path, string path2);
void Desk(string name,string path2);

int main(){

    string path1,path2;
    
    cout<<"enter the path which you want to clean (desktop) \n";
    cin>>path1;
    cout<<"enter the path in which you want to move the files \n";
    cin>>path2;
    
    Desk(path1,path2);
 return 0; 
}



void move_file(string path, string path2){  // This function move the files to folders according to extension.
	string ext=path.substr(path.find_last_of('.')+1);
	string ext_dir=path2+"/"+ext;  
	
	string n=path.substr(path.find_last_of('/')+1);	
	string f=ext_dir+"/"+n;
	if(n!="desktop"){
	
	    char fol[ext_dir.size()+1];
	    strcpy(fol,ext_dir.c_str());
	    fol[ext_dir.size()]='\0';
	        
            mkdir(fol, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
           
            char file_source[path.size()+1];
            strcpy(file_source,path.c_str());
            file_source[path.size()]='\0';
        
            char file_destination[f.size()+1];
            strcpy(file_destination,f.c_str());
            file_destination[f.size()]='\0';
    
       	    int n;
	    char b[1024];
	    int s=open(file_source,O_RDONLY,S_IRWXU);
    	    int d=open(file_destination,O_WRONLY|O_CREAT|O_TRUNC,S_IRWXU);
    	    while((n=read(s,b,1024))>0){
                write(d,b,n);
    	    }
	    close(s);
	    remove(file_source);
	    close(d);

       }
}

void Desk(string name, string path2){  // this function scan all the folders and send path of a file to move_file function.

    DIR *dir; 	
    char s1[name.size()+1];
    strcpy(s1,name.c_str());
    s1[name.size()]='\0';
    	
    struct dirent *pent;
    if (!(dir = opendir(s1)))
        return;
	    
    while(pent = readdir(dir)){
	 string path;
         if(pent->d_type == DT_DIR){
             if (strcmp(pent->d_name, ".")==0 || strcmp(pent->d_name, "..")==0)
                 continue;
             path=name+"/"+pent->d_name; 
             Desk(path,path2);
         } 
	 else{
	      path=name+"/"+pent->d_name;
	      move_file(path,path2);
         }
    } 
    closedir(dir);
}

