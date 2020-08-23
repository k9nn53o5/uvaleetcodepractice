class Solution {
public:
    string reorganizeString(string S) {
        int alpha[26];
        int oddnum=0,evennum=0;
        int len=S.length();
        for(int i=0;i<26;i++){
            alpha[i]=0;
        } 
        for(int i=0;i<len;i++){
            if(S[i]>96 && S[i]<123){
                alpha[S[i]-97]++;
            }
            else{
            }
        }
        for(int i=0;i<26;i++){
            if(alpha[i]%2 == 0 && alpha[i]!=0){
                evennum++;
            }
            else if(alpha[i]%2==1 && alpha[i]!=0){
                oddnum++;
            }
        }
        
        /*
        for(int i=0;i<26;i++){
            cout<<alpha[i]<<" ";
        }
        cout<<endl<<oddnum<<" "<<evennum;
        */
        
        string sout="";
        int odd;
        int oddn;
        if(oddnum<=1){
            for(int i=0;i<26;i++){
                sout=sout+addtostr(i,alpha[i]);
                if(alpha[i]%2==1){
                    odd=i+97;
                    oddn=alpha[i];
                }
            }   
            sout=sout+addtostr(odd-97,oddn-1)+(char)odd+addtostr(odd-97,oddn-1)+sout;
        }
        
       
      //  cout<<sout<<" "<<odd<<" "<<oddn;
        return sout;
    }
    string addtostr(int ch,int num){
        string addstr="";
        if(num>0 && num%2==0){
            addstr=addstr+(char)(ch+97)+addtostr(ch,num-2);
        }    
        return addstr;
    }
};
