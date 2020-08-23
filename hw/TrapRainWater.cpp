#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height);
void QsortHeight(int* arr,int lo,int hi);
int partition(int* arr,int lo,int hi);

int main(){
	int arr[]={0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> height;
	height.assign(arr,arr+12);
	cout<<"output:"<<trap(height);
	return 0;	
}

int trap(vector<int>& height) {
        int len = height.size();
        
        int sortHarr[len];
        for(int i=0;i<len;i++){
            sortHarr[i]=height[i];
        }
        int* sortPtr = sortHarr;
        QsortHeight(sortPtr , 0 , len-1);
        cout<<"sortHarr[]:"<<endl;
        for(int i=0;i<len;i++){
            cout<<sortHarr[i]<<" ";
        }
        
        int poarr[2][len];
        cout<<endl;
        for(int i=0;i<len;i++){
            poarr[1][i]=-1;
        }
        
        int po=0;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(height[i]==sortHarr[j] && poarr[1][j]!=1){
                    poarr[0][j]=i;
                    poarr[1][j]=1;
                    break;
                }
            }   
        }
        cout<<"poarr[][]:"<<endl;
        for(int i=0;i<2;i++){
            for(int j=0;j<len;j++){
                cout<< poarr[i][j]<< " ";
            }
            cout<<endl;
        }
        
        int volumnarr[2][len];
        int nowhighest=sortHarr[len-1];
        int prehighest=0;
        
        for(int i=0;i<len;i++){
            if(sortHarr[i] >= nowhighest){    
                volumnarr[1][i]=poarr[0][i];
                }
            else{
                volumnarr[1][i]=0;
            }
        }
        QsortHeight(volumnarr[1],0,len-1);
        int temp[len];
        for(int i=0;i<len;i++){
        	temp[i]=0;
		}
        for(int i=0;i<len;i++){
        	if(volumnarr[1][i]!=0){
        		temp[volumnarr[1][i]]=volumnarr[1][i];
			}
		}
		for(int i=0;i<len;i++){
			volumnarr[1][i]=temp[i];
		}
		while(1){
		
	        prehighest=nowhighest;
	        if(prehighest==sortHarr[0]){
	        	break;
			}
	        nowhighest=0;
	        for(int i=0;i<len;i++){
	            if(poarr[0][i]>nowhighest && poarr[0][i]<prehighest){
	                nowhighest=poarr[0][i];
	            }
	        }
	        for(int i=0;i<len;i++){
	            volumnarr[0][i]=volumnarr[1][i];
	        }
	        for(int i=0;i<len;i++){
	            if(sortHarr[i] >= nowhighest){    
	                volumnarr[1][i]=poarr[0][i];
	                }
	            else{
	                volumnarr[1][i]=0;
	            }
	            
	        }
	        QsortHeight(volumnarr[1],0,len-1);
	        //int temp[len];
	        for(int i=0;i<len;i++){
	        	temp[i]=0;
			}
	        for(int i=0;i<len;i++){
	        	if(volumnarr[1][i]!=0){
	        		temp[volumnarr[1][i]]=volumnarr[1][i];
				}
			}
			for(int i=0;i<len;i++){
				volumnarr[1][i]=temp[i];
			}
        
    	
	        cout<<"volumnarr[][]:"<<endl;
	        for(int i=0;i<2;i++){
	            for(int j=0;j<len;j++){
	                cout<< volumnarr[i][j]<< " ";
	            }
	            cout<<endl;
	        }
        
    	}
        return 0;
        
    }
   
    void QsortHeight(int* arr,int lo,int hi){

        if(lo<hi){
            int p = partition(arr,lo,hi);
            QsortHeight(arr,lo,p-1);
            QsortHeight(arr,p+1,hi);
        }
       
    }
    
    int partition(int* arr,int lo,int hi){
        int pivot = arr[hi];
        int i= lo;
        for(int j=lo;j<hi;j++){
            if(arr[j]<pivot){
                int temp;
                temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;            
            }
        }
        int temp2=arr[hi];
        arr[hi]=arr[i];
        arr[i]=temp2;
        return i;
    } 
