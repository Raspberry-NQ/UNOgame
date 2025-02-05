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

//随机数
void randomInit(){
    srand((unsigned)time(NULL));
}
int randomOut(int n){//包括上下限
    return (rand()%(n));
}

void SetColor(unsigned short forecolor =4 ,unsigned short backgroudcolor =0)
{
    HANDLE hCon =GetStdHandle(STD_OUTPUT_HANDLE); //获取缓冲区句柄
    SetConsoleTextAttribute(hCon,forecolor|backgroudcolor); //设置文本及背景色
}

/*
在标准UNO牌中，牌型数量如下（总牌数为 108张）：
-----------------------------------------------------------------
1. 数字牌（76张）
0 牌：每种颜色（红、黄、绿、蓝）各 1张 → 4张。

1-9 牌：每种颜色（红、黄、绿、蓝）的每个数字各 2张 → 4色 × 9数字 × 2 = 72张。
总计：4（0牌） + 72（1-9牌） = 76张。
-----------------------------------------------------------------
//0-75：先数字后颜色，
2. 功能牌（32张）
跳过（Skip）：每种颜色各 2张 → 4色 × 2 = 8张。

反转（Reverse）：每种颜色各 2张 → 4色 × 2 = 8张。

+2（Draw Two）：每种颜色各 2张 → 4色 × 2 = 8张。

万能牌（Wild）：无色牌，共 4张。

+4（Wild Draw Four）：无色牌，共 4张。
总计：8 + 8 + 8 + 4 + 4 = 32张。
-----------------------------------------------------------------
3. 总牌数
数字牌（76） + 功能牌（32） = 108张。

关键细节补充：
颜色分配：红、黄、绿、蓝四色均分数字牌和基础功能牌（Skip、Reverse、+2）。

无色牌：万能牌（Wild）和+4牌（Wild Draw Four）不绑定颜色，可匹配任意颜色。

特殊规则：+2和+4牌叠加使用时，下家需累计抓牌（如连续两张+2需抓4张）。

若有特殊版本（如UNO Flip或主题联名版），牌型数量可能不同，但标准版均为 108张。
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
            //初始化牌堆
            for(int i=0;i<108;i++){
                cards[i]=-1;
            }
            //初始化手中牌
            handCard=new VecList<UNOcard*>[playernum];


            //-----------------------
            //发牌
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
            //随机给出初始牌,必须是数字牌
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
                cout<<"蓝";
                break;
            case 1: SetColor(12,0);
                cout<<"红";
                break;
            case 2: SetColor(14,0);
                cout<<"黄";
                break;
            case 3: SetColor(10,0);
                cout<<"绿";
                break;
            case 4:
                SetColor(15,0);
                cout<<"万能";
                break;
                // default: cout<<"?";
        }
        cout<<"色";
        int s= numberOut(c);
        if(s>=0 and s<10){
            cout<<s;
        }
        else if(s==10){
            cout<<"反转";
        }
        else if(s==11){
            cout<<"禁止";
        }
        else if(s==12){
            cout<<"+2";
        }
        else if(s==13){
            cout<<"+4";
        }
        else{
            cout<<"万能牌";
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
        cout<<"最后一张:";
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
        //数字牌0,技能牌1
        if(c<76){
            return 0;
        }
        return 1;
    }
    int colorOut(int c){
        //0->4 蓝红黄绿黑
        if(c>=100){
            // cout<<"黑"<<endl;
            return 4;
        }
        else if( (c>=0 and c<19) or (c>=76 and c<78) or (c>=84 and c<86) or (c>=92 and c<94) ){
            //  cout<<"蓝"<<endl;
            return 0;
        }
        else if( (c>=19 and c<19*2) or (c>=78 and c<80) or (c>=86 and c<88) or (c>=94 and c<96) ){
            // cout<<"红"<<endl;
            return 1;
        }
        else if( (c>=19*2 and c<19*3) or (c>=80 and c<82) or (c>=88 and c<90) or (c>=96 and c<98) ){
            // cout<<"黄"<<endl;
            return 2;
        }
        else if( (c>=19*3 and c<19*4) or (c>=82 and c<84) or (c>=90 and c<92) or (c>=98 ) ){
            // cout<<"绿"<<endl;
            return 3;
        }
        return -1;
    }
    int numberOut(int c){
        //数字0-9,反转10,禁止11,+2:12,+4:13,万能14
        if(kindOut(c)==0){//数字牌
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
        //先颜色
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
            cout<<"输入颜色错误"<<endl;
            throw"error";
        }
        else if(lastCard->color!=5){
            cout<<"当前最后一张牌颜色不可被改变"<<endl;
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
            cout<<"颜色或图案不匹配，无法打出这张牌"<<endl;
            delete out;
            return;
        }
        for(int i=0;i<handCard[player].getLength();i++){
            if(card==handCard[player].getEleAtPos(i)->card){
                cards[out->card]=-1;

                cout<<player<<"号玩家出牌:";
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
        cout<<"该玩家没有这张牌"<<endl;
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
        cout<<"当前手牌";s.printPlayer(0);cout<<endl;
        int input=-1;
        while(input==-1){
            cout<<"输入要打出牌的编号:";
            cin>>input;
            if(input==-1){//摸两张
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
