#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include<bits/stdc++.h>
#include <fcntl.h>
#include<sys/stat.h>
#include <fstream>
#include <string>

using namespace std;

struct mydat{
     string p;  // path of files
     string n;  // name of files
     off_t s;   // size of files
};
vector<mydat> ans;

void put(mydat value);  // put the size, name and path of a file in a vector 
void scan_f(string name); // scan the files

int main(){

  string s;
  cout<<" Enter the path from which you want to see 10 biggest files \n";
  cin>>s;
  cout<<endl;
  
  scan_f(s);
  
  for(int i=9; i>=0; i--){
      cout<<"File name:- "<<ans[i].n<<"\nsize of file:- "<<(double)ans[i].s/(1024*1024)<<" MB"<<endl<<endl;
  }  
  return 0;  
}



void put(mydat value){     // insert the file name,location and size of a file in vector in increasing order of size
      if(ans.size()==0){
         ans.push_back(value);
      }
      else if(ans.size()<10){
         ans.push_back(value);
         mydat temp=ans[ans.size()-1];
         
         int i=ans.size()-2;
         while(i>=0 && temp.s<ans[i].s){
              ans[i+1]=ans[i];
              i--;
         }
         ans[i+1]=temp;
        
      }
      else{
          if(value.s>ans[0].s){
             int i=1;
             while(i<10 && value.s>ans[i].s){
                  ans[i-1]=ans[i];
                  i++;
             }
             ans[i-1]=value;
          
          } 
      }   
}

void scan_f(string name){    // Scan all the folders untill reach to a file 

    DIR *dir;    	
    char s1[name.size()+1];
    strcpy(s1,name.c_str());
    s1[name.size()]='\0';
    	
    struct dirent *pent;
    if (!(dir = opendir(s1))){
        cout<<"this is not a valid path !"<<endl;
        return;
    }    
    while((pent = readdir(dir))!=NULL){
	 string path;
         if (pent->d_type == DT_DIR) {
             if (strcmp(pent->d_name, ".")==0 || strcmp(pent->d_name, "..")==0)
                 continue;
             path=name+"/"+pent->d_name; 
             scan_f(path);
         } 
	 else{
	      path=name+"/"+pent->d_name;
	      
	      char p1[path.size()+1];
              strcpy(p1,path.c_str());
              p1[path.size()]='\0';
                 
              struct stat fs;
              stat(p1,&fs);
              off_t x=fs.st_size;
              
	      mydat var;
	      var.p=name; var.n=pent->d_name; var.s=x;      
	      put(var);
         }
    } 
    closedir(dir);
}

