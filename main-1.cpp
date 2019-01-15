#include <bits/stdc++.h>
using namespace std;
struct sms{
    string fname,lname;
    int sid;
    sms * next;
};

void registerSMS(sms *&head, string nfn, string nln){
    struct sms * n = new sms;
    n->fname = nfn;
    n->lname = nln;
    n->next = NULL;
    if(head ==NULL){
        n->sid = 1;
        head = n;
        cout<<endl<<"Student successfully registered!"<<endl;
        cout<<"Full name : "<<nfn<<" "<<nln<<endl;
        cout<<"Student ID(SID) : "<<1<<endl;
    }else{
        struct sms * temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        n->sid = temp->sid + 1;
        temp->next = n;
        cout<<endl<<"Student successfully registered!"<<endl;
        cout<<"Full name : "<<nfn<<" "<<nln<<endl;
        cout<<"Student ID(SID) : "<<temp->sid + 1<<endl;
    }
}

void deleteSMS(sms *&head, int dsid){
    if(head!=NULL){
        struct sms * temp = head;
        if(temp->next==NULL){
            if(temp->sid==dsid){
                delete temp;
                head =NULL;
                cout<<endl<<"Student successfully removed!"<<endl;
            }else{
                cout<<endl<<"There is no student with this SID, Please enter valid SID9!"<<endl;
            }
        }else{
            while(temp->next->sid!=dsid && temp->next!=NULL){
                temp= temp->next;
            }
            if(temp->next->sid==dsid){
                sms * tempnxt = temp->next->next;
                delete temp->next;
                temp->next = tempnxt;
                cout<<endl<<"Student successfully removed!"<<endl;
            }else{
                cout<<endl<<"There is no student with this SID, Please enter valid SID3!"<<endl;
            }
        }
    }else{
        cout<<endl<<"There is no student to delete!"<<endl;
    }
}

void searchSMS(sms *&head, int ssid){
    if(head!=NULL){
        struct sms * temp = head;
        while(temp->sid!=ssid && temp->next!=NULL){
            temp=temp->next;
        }
        if(temp->sid==ssid){
            cout<<endl<<"Student Found:"<<endl;
            cout<<"Full name : "<<temp->fname<<" "<<temp->lname<<endl;
            cout<<"Student ID(SID) : "<<temp->sid<<endl;
        }else{
            cout<<endl<<"There is no student with this SID!"<<endl;
        }
    }else{
        cout<<endl<<"There is no student to search!"<<endl;
    }
}

void displaySMS(sms *&head){
    if(head!=NULL){
        struct sms * temp = head;
        cout<<endl<<"|"<<setw(15)<<"SID |";
        cout<<setw(20)<<" FIRST NAME |";
        cout<<setw(20)<<" LAST NAME |"<<endl;
        cout<<"-------------------------------------------------------"<<endl;
        while(temp != NULL){
            cout<<"|"<<setw(13)<<temp->sid<<" |";
            cout<<setw(15)<<" "<<temp->fname<<" |";
            cout<<setw(15)<<" "<<temp->lname<<" |"<<endl;
            cout<<"-------------------------------------------------------"<<endl;
            temp = temp->next;
        }
    }else{
        cout<<endl<<"There is no student!"<<endl;
    }
}

void updateSMS(sms *&head, int usid, string nfn="0", string nln="0"){
    if(head!=NULL){
        struct sms * temp = head;
        while(temp->sid!=usid && temp->next!=NULL){
            temp = temp->next;
        }
        if(temp->sid==usid){
            if(nfn!="0"){
                temp->fname = nfn;
            }
            if(nln!="0"){
                temp->lname = nln;
            }
            cout<<endl<<"Student successfully Updated!"<<endl;
            cout<<"Full name : "<<temp->fname<<" "<<temp->lname<<endl;
            cout<<"Student ID(SID) : "<<temp->sid<<endl;
        }else{
            cout<<endl<<"There is no student with this SID, Please enter valid SID!"<<endl;
        }
    }else{
        cout<<endl<<"There is no student to update!"<<endl;
    }
}

bool checkInput(string inp){
    int i;
    for(i=0;i<inp.length();i++){
        if(inp[i]>='0' && inp[i]<='9')return false;
    }
    return true;
}
int main(){
    struct sms * head = NULL;
    int control;
    int rsid;
    string nfname, nlname;
    while(true){
        cout<<"To Register Student-> Enter 1 "<<endl;
        cout<<"To Remove Student -> Enter 2 "<<endl;
        cout<<"To Search For Student -> Enter 3 "<<endl;
        cout<<"To View Students -> Enter 4 "<<endl;
        cout<<"To Update Student -> Enter 5 "<<endl;
        cout<<"To Close Program -> Enter C "<<endl;
        cout<<"ENTER -> ";
        cin>>control;
        switch(control){
        case 1:
            cout<<"Enter First Name : ";
            cin>>nfname;
            cout<<"Enter Last Name : ";
            cin>>nlname;
            if(checkInput(nfname) && checkInput(nlname))registerSMS(head, nfname, nlname);
            else cout<<"Invalid Input!"<<endl;
            break;
        case 2:
            cout<<"Enter Student ID : ";
            cin>>rsid;
            deleteSMS(head, rsid);
            break;
        case 3:
            cout<<"Enter Student ID : ";cin>>rsid;
            searchSMS(head, rsid);
            break;
        case 4:
            displaySMS(head);
        break;
        case 5:
            cout<<"Enter '0' if you don't want to update"<<endl;
            cout<<"Enter Student ID : ";cin>>rsid;
            cout<<"Enter First Name : ";cin>>nfname;
            cout<<"Enter Last Name : ";cin>>nlname;
            updateSMS(head, rsid, nfname, nlname);
        break;
        case 0:
            break;
        default:
            cout<<"please enter correct choice\n";

        }

            /*
        string control;
        cout<<"To Register Student-> Enter 1 "<<endl;
        cout<<"To Remove Student -> Enter 2 "<<endl;
        cout<<"To Search For Student -> Enter 3 "<<endl;
        cout<<"To View Students -> Enter 4 "<<endl;
        cout<<"To Update Student -> Enter 5 "<<endl;
        cout<<"To Close Program -> Enter C "<<endl;
        cout<<"ENTER -> ";
        cin>>control;
        if(control=="c")break;
        else if(control=="1"){
            string nfname, nlname;
            cout<<"Enter First Name : ";cin>>nfname;
            cout<<"Enter Last Name : ";cin>>nlname;
            if(checkInput(nfname) && checkInput(nlname))registerSMS(head, nfname, nlname);
            else cout<<"Invalid Input!"<<endl;
        }else if(control=="2"){
            int rsid;
            cout<<"Enter Student ID : ";cin>>rsid;
            deleteSMS(head, rsid);
        }else if(control=="3"){
            int rsid;
            cout<<"Enter Student ID : ";cin>>rsid;
            searchSMS(head, rsid);
        }else if(control=="4"){
            displaySMS(head);
        }else if(control=="5"){
            int rsid;
            string nfname, nlname;
            cout<<"Enter '0' if you don't want to update"<<endl;
            cout<<"Enter Student ID : ";cin>>rsid;
            cout<<"Enter First Name : ";cin>>nfname;
            cout<<"Enter Last Name : ";cin>>nlname;
            updateSMS(head, rsid, nfname, nlname);
        }
        cout<<endl;
    */
    }//end of while

}
