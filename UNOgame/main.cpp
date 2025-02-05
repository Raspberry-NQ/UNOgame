#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iomanip>
//#include "stdafx.h"
//0black;9blue;10green;12red;14yellow;7white;15whiteh
/*
                                                      ..::::------------::::.
                                             .::--------------------------=+++++++++=-:.
                                        .::--------------------------:-+##**++=======++***-
                                    .::-----------------------------=#%*==+*##%%%%%%##*+==+#*:
                                 .:------------------------=+=----+%%=-+#%%%%%%%%%%%#%%%%%*=-#*.
                              .:----------------------=+**#**@+:+%%- +%%%%#%%%%%##%%%%%##%%%#--@=
                           .:--------------------:-*##*++==+.=@#@=  %@%#%#%%*-..   .:+#%%%%#%@=.%+
                         .-----------------------*%*:.+*#%%%@ *%.  %%#%%%@+          ..=%%#%%#@* @=
                       :--------------=+*+-----*%*:.- =@%%%#%#    +@#%%#@= -+++=:  :---.:%%%%%#@=:@:
                     :----------=+**##**+*##+-:%% :--- *@#%%#@+   %%%%%%% #%+++*##=.:-:. :@%%%%%@ ##
                   :----:--=+***#*+==++**+=+*##+@+ --.  %%%%%#@-  %%%%%%% @*:----=%* . .- *%#%%#@-=@
                 .-----=*#**++==: .%%%%%%%%#+=+*%@-. .-.:@%%%%%@. %%%%%#@.+@-------%# ::  =@#%%#@=-@
                :----=%%=:=+*##%@. +@#%%%#%%%%#+==+ .-.  =@#%%#%% +@#%%#%# %%------=@-    *%#%%#@:=%
            .------=#%=.: +@%%%#%#  #%#%%%%%##%%%#+-      *@#%%#@+ %%#%%#%#.*%+=----@+   =@#%%#%% %+
      .:=+**+=%#:--@@ .--- *%#%%#@+ .@%%%%%%%%%##%%%%*-    %%%%%#@-.%%#%%#%%=-+****#*  :*@%%%#%@:+%
   .*#*+===+*= @+--=@= --:  %%%%%#@- -@#%%%%@*#%%%##%%%%*- .%%%%%%@..#@%#%#%%#*+====-+#%%#%##%%:=@.
 .*%=  *#%%%%@:-@=--*@:.. :.:@#%%%%@. +@#%%#%* :+#%%%##%%%%+#@#%%#%%  =%%%%##%%%%%%%%%%###%%@*.+%.
*%=    :@####%@ *@---%@ .-:  =@#%%#%#  #%#%%#@+   :+#%%%##%%%%%%%%#@*   =#%%%%%######%%%%%%+.:#+
#%      =@#%%#%# %#---@#      #%#%%#@+ .@%%%%#@-     :+#%%%###%%%%%#@-    .-+#%%%%%%%%#*=: .+#:
 %#      *%#%%#@+ @+--=@=      %%%%%#@- -@#%%%%%.       :+#%%%##%%%%%@.        ..::..    :*#-
 .@=      %%%%%#@:-@=--*@:     :@%%%%%@. +@#%%#%#          :+#%%%##%#%%.             .-*#*:
  =@:     :@#%%%%@ *@---%@      +@#%%#@*  #%#%%#@= +.         :+#%%%%#*..#+==---=++*#*=:
   *@   :- =@#%%#%# %#:--@#      %%%%%%%  .@%%%%#@:+@#+:         :-.   =%#+*******+-
    %# ---- *%#%%#@+ @*::=@=     @%%%%%@.  -@#%%#%% #@*%#+:         :+%#=---:::--:
    .@= -:.  %%#%%#@=.##+=%@    *@#%%%%%    +@#%%%@# %*:=*%#+:.-=*###*=:--------.
     =@:  .-.:@%#%%#@*-=++*+ .=#%#%%#%@-     #%#*+:..#@----=*###*+=--:--------.
      *@ :-   :%%##%#%%#****#%%%#%#%%%-       .   .+%*----------------------.
       %#      .*%%%%##%%%%%%##%%%%%+:+@.     .-+*%#---------------------:.
        %#       :*%%%%%%%%%%%%%#+::+%#%%:-+*###*+---------------------:
         #%:        :=+*****+=:  .+%#=:-##*+=-----------------------:.
          =%*:                 -*%#=:----------------------------:.
            =##=:.        .-+#%#+-:--------------------------:.
              .-+*******####*=--------------------------::.
                    .:----------------------------::..
                          .::::----------::::..
*/
/*
 *
    ___       ___       ___
   /\__\     /\__\     /\  \
  /:/ _/_   /:| _|_   /::\  \
 /:/_/\__\ /::|/\__\ /:/\:\__\
 \:\/:/  / \/|::/  / \:\/:/  /
  \::/  /    |:/  /   \::/  /
   \/__/     \/__/     \/__/
 */

#include <windows.h>
using namespace std;

template <class T>
class VecList{
private:
    int capacity;
    int length;
    T* arr;
    void doubleListSize(){
        T * oldArr = arr;
        arr = new T[2*capacity];
        capacity = 2 * capacity;
        for(int i=0;i<length;i++){
            arr[i] = oldArr[i];
        }
        delete [] oldArr;
    }
public:
    VecList(){
        length = 0;
        capacity = 100;
        arr = new T[capacity];
    }
    VecList(T* a, int n){
        length = n;
        capacity = 100 + 2*n;
        arr = new T[capacity];
        for(int i=0;i<n;i++){
            arr[i] = a[i];
        }
    }
    ~VecList(){
        delete [] arr;
    }
    int getLength(){
        return length;
    }
    bool isEmpty(){
        return length==0;
    }
    void insertEleAtPos(int i, T x){
        if(length==capacity)
            doubleListSize();
        if(i > length || i < 0)
            throw "Illegal position";
        for(int j=length;j>i;j--)
            arr[j] = arr[j-1];
        arr[i] = x;
        length++;
    }
    T deleteEleAtPos(int i){
        if(i >= length || i < 0)
            throw "Illegal position";
        T tmp = arr[i];
        for(int j=i;j<length-1;j++)
            arr[j] = arr[j+1];
        length--;
        return tmp;
    }
    void setEleAtPos(int i, T x){
        if(i >= length || i < 0)
            throw "Illegal position";
        arr[i] = x;
    }
    void insertAtEnd(T x){
        insertEleAtPos(length,x);
    }
    T getEleAtPos(int i){
        if(i >= length || i < 0)
            throw "Illegal position";
        return arr[i];
    }


    int findLocation(T x){
        for(int i=0;i<length;i++){
            if(arr[i]==x)
                return i;
        }
        return -1;
    }
    void printList(){
        for(int i=0;i<length;i++)
            cout << arr[i] << " ";
    }
};

//�����
void randomInit(){
    srand((unsigned)time(NULL));
}
int randomOut(int n){//����������
    return (rand()%(n));
}

void SetColor(unsigned short forecolor =4 ,unsigned short backgroudcolor =0)
{
    HANDLE hCon =GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ���������
    SetConsoleTextAttribute(hCon,forecolor|backgroudcolor); //�����ı�������ɫ
}

/*
�ڱ�׼UNO���У������������£�������Ϊ 108�ţ���
-----------------------------------------------------------------
1. �����ƣ�76�ţ�
0 �ƣ�ÿ����ɫ���졢�ơ��̡������� 1�� �� 4�š�

1-9 �ƣ�ÿ����ɫ���졢�ơ��̡�������ÿ�����ָ� 2�� �� 4ɫ �� 9���� �� 2 = 72�š�
�ܼƣ�4��0�ƣ� + 72��1-9�ƣ� = 76�š�
-----------------------------------------------------------------
//0-75�������ֺ���ɫ��
2. �����ƣ�32�ţ�
������Skip����ÿ����ɫ�� 2�� �� 4ɫ �� 2 = 8�š�

��ת��Reverse����ÿ����ɫ�� 2�� �� 4ɫ �� 2 = 8�š�

+2��Draw Two����ÿ����ɫ�� 2�� �� 4ɫ �� 2 = 8�š�

�����ƣ�Wild������ɫ�ƣ��� 4�š�

+4��Wild Draw Four������ɫ�ƣ��� 4�š�
�ܼƣ�8 + 8 + 8 + 4 + 4 = 32�š�
-----------------------------------------------------------------
3. ������
�����ƣ�76�� + �����ƣ�32�� = 108�š�

�ؼ�ϸ�ڲ��䣺
��ɫ���䣺�졢�ơ��̡�����ɫ���������ƺͻ��������ƣ�Skip��Reverse��+2����

��ɫ�ƣ������ƣ�Wild����+4�ƣ�Wild Draw Four��������ɫ����ƥ��������ɫ��

�������+2��+4�Ƶ���ʹ��ʱ���¼����ۼ�ץ�ƣ�����������+2��ץ4�ţ���

��������汾����UNO Flip�����������棩�������������ܲ�ͬ������׼���Ϊ 108�š�
 */

struct UNOcard{
    int card;
    int kind;
    int color;
    int number;

};
class UNOgame{
private:
    const unsigned int initialCardNumber=3;
    const unsigned int maxCardNumber=32;
    int playerNumber;
    int cards[108];
    //int **handCard;
    VecList<UNOcard*> *handCard;
    UNOcard *lastCard=NULL;
    int playerNow=-1;
    bool upDirect=true;
    bool ended=false;
public:
    UNOgame(int playernum){
        playerNumber=playernum;
        if(playernum>=2 and playernum<=8){
            //��ʼ���ƶ�
            for(int i=0;i<108;i++){
                cards[i]=-1;
            }
            //��ʼ��������
            handCard=new VecList<UNOcard*>[playernum];


            //-----------------------
            //����
            for(int i=0;i<playerNumber;i++){
                for(int k=0;k<initialCardNumber;k++){
                    int cardChoose= randomOut(107);
                    //cout<<cardChoose<<endl;
                    while(cards[cardChoose]!=-1){
                        cardChoose= randomOut(107);
                    }
                    cards[cardChoose]=i;

                    UNOcard *o=new UNOcard{cardChoose,kindOut(cardChoose), colorOut(cardChoose), numberOut(cardChoose)};
                    handCard[i].insertAtEnd(o);
                }
            }
            //���������ʼ��,������������
            int cardChoose= randomOut(107);
            //cout<<cardChoose<<endl;
            while(cards[cardChoose]!=-1 or kindOut(cardChoose)==1){
                cardChoose= randomOut(107);
            }
            UNOcard *o=new UNOcard{cardChoose,kindOut(cardChoose), colorOut(cardChoose), numberOut(cardChoose)};
            setLastCard(o);
        }
        else{
            cout<<"ERROR @ 100";
            throw "error 100";
        }
    }
    ~UNOgame(){

    }
    //---------------------------------------------------
    void printCardofID(int c){//0black;9blue;10green;12red;14yellow;7white;15whiteh
        switch(colorOut(c)){
            case 0: SetColor(9,0);
                cout<<"��";
                break;
            case 1: SetColor(12,0);
                cout<<"��";
                break;
            case 2: SetColor(14,0);
                cout<<"��";
                break;
            case 3: SetColor(10,0);
                cout<<"��";
                break;
            case 4:
                SetColor(15,0);
                cout<<"����";
                break;
                // default: cout<<"?";
        }
        cout<<"ɫ";
        int s= numberOut(c);
        if(s>=0 and s<10){
            cout<<s;
        }
        else if(s==10){
            cout<<"��ת";
        }
        else if(s==11){
            cout<<"��ֹ";
        }
        else if(s==12){
            cout<<"+2";
        }
        else if(s==13){
            cout<<"+4";
        }
        else{
            cout<<"������";
        }
        SetColor(15,0);
    }

    void printcard(UNOcard *x){
        printCardofID(x->card);
    }

    void printHandCard(){
        for(int i=0;i<playerNumber;i++){
            cout<<"Player "<<i+1<<" : ";
            for(int k=0;k<handCard[i].getLength();k++){
                printcard(handCard[i].getEleAtPos(k));
                cout<<" | ";
            }
            cout<<endl;
        }
    }

    void printGame(){
        cout<<"���һ��:";
        printcard(lastCard);
        cout<<endl;
        for(int i=0;i<playerNumber;i++){
            cout<<"Player "<<i<<" : ";
            cout<<handCard[i].getLength();
            cout<<" cards left.";
            cout<<endl;
        }

    }
    void printPlayer(int player){
        for(int k=0;k<handCard[player].getLength();k++){
            printcard(handCard[player].getEleAtPos(k));
            cout<<"("<<handCard[player].getEleAtPos(k)->card<<")";
            cout<<" | ";
        }

    }

    int kindOut(int c){
        //������0,������1
        if(c<76){
            return 0;
        }
        return 1;
    }
    int colorOut(int c){
        //0->4 ������̺�
        if(c>=100){
            // cout<<"��"<<endl;
            return 4;
        }
        else if( (c>=0 and c<19) or (c>=76 and c<78) or (c>=84 and c<86) or (c>=92 and c<94) ){
            //  cout<<"��"<<endl;
            return 0;
        }
        else if( (c>=19 and c<19*2) or (c>=78 and c<80) or (c>=86 and c<88) or (c>=94 and c<96) ){
            // cout<<"��"<<endl;
            return 1;
        }
        else if( (c>=19*2 and c<19*3) or (c>=80 and c<82) or (c>=88 and c<90) or (c>=96 and c<98) ){
            // cout<<"��"<<endl;
            return 2;
        }
        else if( (c>=19*3 and c<19*4) or (c>=82 and c<84) or (c>=90 and c<92) or (c>=98 ) ){
            // cout<<"��"<<endl;
            return 3;
        }
        return -1;
    }
    int numberOut(int c){
        //����0-9,��ת10,��ֹ11,+2:12,+4:13,����14
        if(kindOut(c)==0){//������
            int c1=c%19;
            if(c1==0){
                return 0;
            }
            else{
                return (c1+1)/2;
            }
        }
        else{
            if(c>=76 and c<84){
                return 10;
            }
            else if(c>=84 and c<92){
                return 11;
            }
            else if(c>=92 and c<100){
                return 12;
            }
            else if(c>=100 and c<104){
                return 13;
            }
            else{
                return 14;
            }
        }
    }
    bool cardMatch(UNOcard *s){
        //����ɫ
        if(s->color==4 or lastCard->color==4){
            return true;
        }
        else if(s->number == lastCard->number){
            return true;
        }
        else if(lastCard->number ==12){
            if(s->number ==12 or s->number==13){
                return true;
            }

        }
        else if(lastCard->color == s->color){
            return true;
        }
        return false;
    }

    UNOcard *getNewCard(int player){
        int cardChoose= randomOut(107);
        //cout<<cardChoose<<endl;
        while(cards[cardChoose]!=-1){
            cardChoose= randomOut(107);
        }
        UNOcard *newCard=new UNOcard{cardChoose,kindOut(cardChoose), colorOut(cardChoose), numberOut(cardChoose)};
        handCard[player].insertAtEnd(newCard);

        return newCard;
    }

    void setLastCard(UNOcard *l){
        cards[l->card]=-1;
        lastCard=l;
    }
    void setLastCardColor(int color){
        if(color<0 or color>4){
            cout<<"������ɫ����"<<endl;
            throw"error";
        }
        else if(lastCard->color!=5){
            cout<<"��ǰ���һ������ɫ���ɱ��ı�"<<endl;
            throw "error";
        }
        else{
            UNOcard *newlast=new UNOcard{-1,1,color,15};
            lastCard=newlast;
        }
    }
    void playCard(int player,int card){
        UNOcard *out=new UNOcard{card,kindOut(card), colorOut(card), numberOut(card)};
        if(cardMatch(out)==false){
            cout<<"��ɫ��ͼ����ƥ�䣬�޷����������"<<endl;
            delete out;
            return;
        }
        for(int i=0;i<handCard[player].getLength();i++){
            if(card==handCard[player].getEleAtPos(i)->card){
                cards[out->card]=-1;

                cout<<player<<"����ҳ���:";
                printcard(out);
                cout<<endl;

                handCard[player].deleteEleAtPos(i);
                lastCard=out;
                if(handCard[player].getLength()==0){
                    ended=true;
                }
                return;
            }
        }
        cout<<"�����û��������"<<endl;
        delete out;
    }
    bool isend(){
        return ended;
    }
    void autoPlayOnce(int player){
        for(int i=0;i<handCard[player].getLength();i++){
            if(cardMatch(handCard[player].getEleAtPos(i))){
                
            }
        }
    }
};

int main() {

    SetColor(15,0);


    //cin>>p;
    randomInit();
    UNOgame s(2);
    //s.printHandCard();
    cout<<""<<endl;
    s.printGame();
    while(s.isend()==false){
        s.printGame();
        cout<<"��ǰ����";s.printPlayer(0);cout<<endl;
        int input=-1;
        while(input==-1){
            cout<<"����Ҫ����Ƶı��:";
            cin>>input;
            if(input==-1){//������
                s.getNewCard(0);
                s.getNewCard(0);
                s.printGame();
                s.printPlayer(0);
                cout<<endl;
            }
        }

        s.playCard(0,input);
    }





    return 0;
}
