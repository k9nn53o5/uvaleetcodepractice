#include <iostream>
#include <vector>
using namespace std;

int main(){
        vector<int> height;
        int kase=1;
        while(1){
                int h=0;
                cin>>h;
                if(h!=-1){
                        height.insert(height.end(),h);
                }
                else if(height.size()==0 && h==-1){break;}
                else if(height.size()!=0 && h==-1){
                        int max=0;
//                      int lasth=9999999;
                        vector<int> lowernum(height.size(),0);
                        for(int i=0;i<height.size();i++){
                                int lasth=999999;
                                if(height[i]<height[0] || i==0){
                                        for(int j=i+1;j<height.size();j++){
                                                if(height[j]<height[i] && height[j]<lasth){
                                                        lasth=height[j];
                                                        lowernum[i]++;
                                                }
                                        }
                                }
                        }
                        for(int i=0;i<lowernum.size();i++){
                                cout<<lowernum[i]<<" ";
                        }
                        cout<<endl;
                        return 0;
                        /*
//                      cout<<"ok"<<endl;
                        for(int i=lowernum.size()-2;i>=0;i--){
                                for(int j=i+1;j<lowernum.size()-1;j++){
                                        if(height[i]>height[j] && lowernum[i]<lowernum[j]+1 && (height[i]<height[0]|| i==0)){
                                                lowernum[i]=lowernum[j]+1;
                                        }
                                }
                        }
//                      cout<<"ok"<<endl;
                        for(int i=0;i<lowernum.size();i++){
                                cout<<lowernum[i]<<" ";
                        }
//                      cout<<"ok"<<endl;
                        printf("Test #%d:\n  maximum possible interceptions: %d\n",kase++,lowernum[0]+1);
                        //intial vector
                        height.clear();
                        */
                }
        }
        return 0;
}

