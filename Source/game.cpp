#include<simplecpp>
#include<windows.h>
#include<cstdlib>
#include<time.h>
#include<string.h>


using namespace std;

class playerinfo
{
   public:
    int bankbalance;
    int position_current;//stores current square number of player
    int properties[30];//stores the data of the properties the player has bought and the dhares built on it
    playerinfo()
    {
        bankbalance = 1500;
        position_current = 1;
        for(int i=0;i<30;i++)
        {
            properties[i]=0;//assigning zero to properties indicates that they have not been bought by player
        }
    }

};

class companydata
{
    public:
     int intereststats[4];                                      //to store all the prices basic interest t3s rent t2s rent etc later;
     string companyname;                                        //an array to store the basic interest etc bi in 0 t3s in 1 and so on
     int pricestats[4];                                         //pricestats[0]=bi;pricestats[1]=t3s;pricestats[2]=t2s;pricestats[3]=t1s;
     int showstats;                                             //shows if a company is bought or not and the shares built on it;
};

bool balance_check_2(const int &balance, const int &token)        //checks if player is terminated or no
{
    bool flag = true;
    if (balance<=0)
    {
            flag = false;
            exit(0);

    cout<<"Player "<<token + 1<<"is eliminated "<<endl;
    cout<<"Other Player Wins !"<<endl;
    }
    return flag;
}

bool balance_check_exit(const int &balance)
{

        bool flag = true;
        if(balance <=0 )
        {
            flag = false;
        }
        return flag;
}


bool balance_check_4(const int &balance, const int &token, int &players_remaining, int* properties) //checks if balance is less than zero
{
    bool flag = true;
    if(players_remaining>2)
    {
        if (balance<=0)
    {
            flag = false;
            for(int i=0;i<29;i++)
            {
                properties[i]=0;
            }

    cout<<"Player "<<token + 1<<" is eliminated "<<endl;
    players_remaining -- ;
    }
    }
    else
    {
        if(balance<=0)
        {
            flag = false;
            cout<<"Player "<<token + 1<<" is eliminated "<<endl;
            exit(0);
        }
    }
    return flag;
}

void chance_exit(int &n, const int &balance)
{
    int r;
    cout<<"Enter 2 to end your turn "<<endl;
    cin>>r;
    if(r==2)
    {
        n = (n+1)%2 ;
    }
    else
    {
        cout<<"\n Wrong Input , Chance still Ends ";
        n = (n+1)%2;
    }
}

void chance_exit_4 (int &n, const int &balance , const int &balance3)
{
    int r;
    cout<<"Enter 2 to end your turn "<<endl;
    cin>>r;
    if(r==2)
    {
        if(balance_check_exit(balance))
        {
                n=(n+1)%4;
        }
        else
        {
            if(balance_check_exit(balance3))
            {
                n=(n+2)%4;
            }
            else
            {
            n=(n+3)%4;
            }
        }

    }
    else
    {
        cout<<"\n Invalid Input , Still chance ends\n\n";
         if(balance_check_exit(balance))
        {
                n=(n+1)%4;
        }
        else
        {
            if(balance_check_exit(balance3))
            {
                n=(n+2)%4;
            }
            else
            {
            n=(n+3)%4;
            }
        }
    }

}

void display_info(int n)//Displays the information of the company when a player lands on it
{
    switch(n)

{

    case 2:
        {
             MessageBox(NULL ,"Company Name : Ferrari    \n Company Price $60   \n Basic Interest                        $10\n Price of Tier III Share           $70\n Price of Tier II Share            $150\n Price of Tier I Share             $200\n Interest of Tier III Share       $50\n Interest of Tier II Share        $100\n Interest of Tier I Share         $300" ,"Information Box", MB_OK);
        }
        break;
    case 3:
        {
             MessageBox(NULL ,"Company Name : Audi  \n Company Price $70  \n Basic Interest                        $10\n Price of Tier III Share           $70\n Price of Tier II Share            $150\n Price of Tier I Share             $200\n Interest of Tier III Share       $60\n Interest of Tier II Share        $150\n Interest of Tier I Share         $350" ,"Information Box", MB_OK);
        }
        break;
    case 5:
        {
             MessageBox(NULL ,"Company Name : Pizza Hut   \n Company Price $80  \n Basic Interest                        $15\n Price of Tier III Share           $80\n Price of Tier II Share            $200\n Price of Tier I Share             $300\n Interest of Tier III Share       $70\n Interest of Tier II Share        $150\n Interest of Tier I Share         $350" ,"Information Box", MB_OK);
        }
        break;
    case 7:
        {
             MessageBox(NULL ,"Company Name : Taco Bell  \n Company Price $100  \n Basic Interest                        $15\n Price of Tier III Share           $80\n Price of Tier II Share            $200\n Price of Tier I Share             $300\n Interest of Tier III Share       $80\n Interest of Tier II Share        $200\n Interest of Tier I Share         $400" ,"Information Box", MB_OK);
        }
        break;
    case 9:
        {
             MessageBox(NULL ,"Company Name : Pringles  \n Company Price $120  \n Basic Interest                        $20\n Price of Tier III Share           $100\n Price of Tier II Share            $200\n Price of Tier I Share             $350\n Interest of Tier III Share       $100\n Interest of Tier II Share        $200\n Interest of Tier I Share         $450" ,"Information Box", MB_OK);
        }
        break;
    case 10:
        {
             MessageBox(NULL ,"Company Name : Lays  \n Company Price $140 \n Basic Interest                        $20\n Price of Tier III Share           $100\n Price of Tier II Share            $200\n Price of Tier I Share             $350\n Interest of Tier III Share       $100\n Interest of Tier II Share        $250\n Interest of Tier I Share         $500" ,"Information Box", MB_OK);
        }
        break;
    case 12:
        {
             MessageBox(NULL ,"Company Name : Versace  \n Company Price $150   \n Basic Interest                        $25\n Price of Tier III Share           $120\n Price of Tier II Share            $250\n Price of Tier I Share             $450\n Interest of Tier III Share       $110\n Interest of Tier II Share        $250\n Interest of Tier I Share         $600" ,"Information Box", MB_OK);
        }
        break;
    case 14:
        {
             MessageBox(NULL ,"Company Name : Tommy Hilfiger  \n Company Price $180   \n Basic Interest                        $25\n Price of Tier III Share           $120\n Price of Tier II Share            $250\n Price of Tier I Share             $450\n Interest of Tier III Share       $110\n Interest of Tier II Share        $300\n Interest of Tier I Share         $650" ,"Information Box", MB_OK);
        }
        break;


    case 16:
        {
             MessageBox(NULL ,"Company Name : Rolex  \n Company Price $200   \n Basic Interest                        $30\n Price of Tier III Share           $150\n Price of Tier II Share            $300\n Price of Tier I Share             $550\n Interest of Tier III Share       $120\n Interest of Tier II Share        $300\n Interest of Tier I Share         $700" ,"Information Box", MB_OK);
        }
        break;


    case 17:
        {
             MessageBox(NULL ,"Company Name : Tissot  \n Company Price $220   \n Basic Interest                        $35\n Price of Tier III Share           $150\n Price of Tier II Share            $300\n Price of Tier I Share             $550\n Interest of Tier III Share       $120\n Interest of Tier II Share        $350\n Interest of Tier I Share         $800" ,"Information Box", MB_OK);
        }
        break;


    case 19:
        {
             MessageBox(NULL ,"Company Name : Facebook  \n Company Price $250   \n Basic Interest                        $50\n Price of Tier III Share           $200\n Price of Tier II Share            $350\n Price of Tier I Share             $650\n Interest of Tier III Share       $150\n Interest of Tier II Share        $350\n Interest of Tier I Share         $900" ,"Information Box", MB_OK);
        }
        break;


    case 21:
        {
             MessageBox(NULL ,"Company Name : Youtube  \n Company Price $270   \n Basic Interest                        $60\n Price of Tier III Share           $200\n Price of Tier II Share            $350\n Price of Tier I Share             $650\n Interest of Tier III Share       $200\n Interest of Tier II Share        $400\n Interest of Tier I Share         $1000" ,"Information Box", MB_OK);
        }
        break;


    case 23:
        {
             MessageBox(NULL ,"Company Name :Apple   \n Company Price $300   \n Basic Interest                        $80\n Price of Tier III Share           $250\n Price of Tier II Share            $400\n Price of Tier I Share             $750\n Interest of Tier III Share       $250\n Interest of Tier II Share        $500\n Interest of Tier I Share         $1100" ,"Information Box", MB_OK);
        }
        break;



    case 25:
        {
             MessageBox(NULL ,"Company Name : Google  \n Company Price $350  \n Basic Interest                        $90\n Price of Tier III Share           $250\n Price of Tier II Share            $400\n Price of Tier I Share             $750\n Interest of Tier III Share       $300\n Interest of Tier II Share        $600\n Interest of Tier I Share         $1200" ,"Information Box", MB_OK);
        }
        break;



    case 26:
        {
             MessageBox(NULL ,"Company Name : Ducati  \n Company Price $400   \n Basic Interest                        $100\n Price of Tier III Share           $300\n Price of Tier II Share            $500\n Price of Tier I Share             $900\n Interest of Tier III Share       $350\n Interest of Tier II Share        $700\n Interest of Tier I Share         $1300" ,"Information Box", MB_OK);
        }
        break;



    case 28:
        {
             MessageBox(NULL ,"Company Name : Harley Davidson  \n Company Price $450   \n Basic Interest                        $150\n Price of Tier III Share           $300\n Price of Tier II Share            $500\n Price of Tier I Share             $900\n Interest of Tier III Share       $400\n Interest of Tier II Share        $800\n Interest of Tier I Share         $1500" ,"Information Box", MB_OK);
        }
        break;
}
}

void sell(companydata*p3,playerinfo*info3,int j3,int n)//sell enables players to sell property to one another  n is number of players playing game j3 is player number(who has his turn)
{   int icheck;//a variable used in the for loop for array elements
    int checker=0;//checks is player actually owns any  property or no
    if(info3[j3-1].bankbalance<=500)
    {
        for(icheck=0;icheck<=27;icheck++)
            {if(info3[j3-1].properties[icheck]>=1)
                {checker=1;}
        }
        if(checker>0)
        {
            cout<<"\nDo you wish to sell any of your companies? Enter y or n : \n ";
            char ans;
            cin>>ans;
            if(ans=='y')
            {
            int jbuyer;
            cout<<"\nPlease enter the number of companies you want to sell :  ";
            int no;//number of companies he wants to sell
            cin>>no;
                repeat(no)
                {
                    cout<<"\nPlease enter the name of the company that you wish to sell in small letters and without any spaces :  ";
                    string sellcompanyname;
                    cin>>sellcompanyname;
                    int sellcompanyindex=100;//sellcompany index has to be greater than 28
                    int finder;//finds the company index

                    for(finder=0;finder<=27;finder++)
                    {
                        if((p3[finder].companyname).compare(sellcompanyname)==0)
                        {
                            sellcompanyindex=finder+1;
                        }
                    }
                    if(info3[j3-1].properties[sellcompanyindex]==0)
                    {
                        cout<<"\nYou do not own this company\n";
                        continue;
                    }
                    if(sellcompanyindex==100)
                    {
                        cout<<"\nPlease enter a valid  company name in small letters :  ";
                        continue;
                    }
                    cout<<"\nPlease enter the player number to whom you wish to sell your property :  ";
                    cin>>jbuyer;
                    int i3;
                    i3=info3[j3-1].position_current;
                    if((jbuyer>=1)&&(jbuyer<=n))
                    {
                        int sellvalue;//stores the value at which a company is sold
                        cout<<"\nPlease enter the price at which you wish to sell :  ";
                        cin>>sellvalue;
                        cout<<"\nPlayer "<<jbuyer<<"  Please confirm the  deal by pressing 'd'  :  ";
                        char confirm;
                        cin>>confirm;
                        if(confirm=='d'&&(info3[jbuyer-1].bankbalance-sellvalue>=0))
                        {cout<<"\nThe deal was successful !!  \n";
                        info3[jbuyer-1].properties[sellcompanyindex]=info3[j3-1].properties[sellcompanyindex];
                        info3[j3-1].properties[sellcompanyindex]=0;
                        info3[jbuyer-1].bankbalance=info3[jbuyer-1].bankbalance-sellvalue;//add case of bankrupt
                        info3[j3-1].bankbalance=info3[j3-1].bankbalance+sellvalue;

                        }
                        else
                        {
                            cout<<"\n The deal was not successful \n";

                        }

        }
                    else
                    {
                        cout<<"\nInvalid input the deal was not succesful  \n";

                    }
            }
        }

            else
            {
                cout<<"\nYou chose not to sell any of your companies \n";
            }

        }

        }

}


void auction(companydata*d2,playerinfo* info5,int j5,int n,int &buycheck,int &fcallcheck)
{
    if(buycheck==0&&fcallcheck==1)//fcallcheck checks whether player can buy property and buycheck checks whether player buys company or no
    {
        cout<<"\nThe auction is about to start";
        cout<<"\nThis auction has two rounds";
        cout<<"\nRound one is about to start";
        int playerindex,playerprice;
        int finderindex=100;
        cout<<"\nPlease enter your prices one by one starting from player 1 :  ";
        int maxcheck=((d2[info5[j5-1].position_current-1].pricestats[0])/2);
        for(playerindex=0;playerindex<=n-1;playerindex++)
        {
            cout<<"\nPlayer "<<(playerindex+1)<<"\nPlease enter your price"<<"\nYour price should be greater than half the cost of the company  :  ";
            cin>>playerprice;//stores each players bid

            if(playerprice>maxcheck)
            {
                maxcheck=playerprice;//finds maxbid
                finderindex=playerindex;//finds maxbidder's index
            }
        }
        if(finderindex==100)
        {
            cout<<"\n Company is not auctioned as no one bid above half the price ! \n";
        }
        if(finderindex!=100)
        {
            if(info5[finderindex].bankbalance-maxcheck>0)
            {
                info5[finderindex].bankbalance-=maxcheck;
                info5[finderindex].properties[info5[j5-1].position_current]=1;
            }
            else
            {
                cout<<"\nPlayer does not have enough balance\n";
            }
    }
    if(finderindex!=100)
    {
        cout<<"\nRound two is about to start ";
        cout<<"\nDoes anyone want to bid higher than "<<maxcheck<<" ?  Enter y or n  :  ";
        char ans5;
        int fbid,fplayernumber;
        cin>>ans5;
        if(ans5=='y')
        {
            cout<<"\nPlease enter your player number :  ";
            cin>>fplayernumber;
            if(fplayernumber>=0&&fplayernumber<=n)
            {
                cout<<"\nPlease enter your final bid  :  ";
                cin>>fbid;
                if(fbid>maxcheck&&(info5[fplayernumber-1].bankbalance-fbid)>0)
                {
                    info5[finderindex].bankbalance+=maxcheck;
                    info5[finderindex].properties[info5[j5-1].position_current]=0;
                    info5[fplayernumber-1].bankbalance-=fbid;
                    info5[fplayernumber-1].properties[info5[j5-1].position_current]=1;
                    cout<<"\n The company has been sold to player "<<fplayernumber<<" for "<<fbid<<endl;
                }
                else
                {
                    cout<<"\nThe company has been sold to player "<<finderindex+1<<" for "<<maxcheck;
                }
            }
            else
            {
                    cout<<"\n Invalid player number \n";
            }
        }
        else
        {
            cout<<"\n The company has been sold to player "<<finderindex+1<<" for "<<maxcheck<<endl;
        }
    }
    }
    buycheck=0;
    fcallcheck=0;

}


void buy_property(int &balance, int* property, int * property2, const int &position,int &buycheck,int &fcallcheck)
{

     companydata data[28];// stores data of companies for computer reference

    for(int i=0;i<28;i++)
    {
    data[i].showstats=0;
    }

    data[0].showstats=10;//assigning the non buyable places to 10
    data[3].showstats=10;
    data[5].showstats=10;
    data[7].showstats=10;
    data[10].showstats=10;
    data[12].showstats=10;
    data[14].showstats=10;
    data[17].showstats=10;
    data[19].showstats = 10;  //remember waterworks
    data[21].showstats=10;
    data[23].showstats=10;
    data[26].showstats=10;


        data[1].companyname="ferrari";
        data[1].pricestats[0]=60;

        data[2].companyname="audi";
        data[2].pricestats[0]=70;

        data[4].companyname="pizzahut";
        data[4].pricestats[0]=80;

        data[6].companyname="tacobell";
        data[6].pricestats[0]=100;

        data[8].companyname="pringles";
        data[8].pricestats[0]=120;

        data[9].companyname="lays";
        data[9].pricestats[0]=140;

        data[11].companyname="Versace";
        data[11].pricestats[0]=150;

        data[13].companyname="Tommy Hilfiger";
        data[13].pricestats[0]=180;

        data[15].companyname="rolex";
        data[15].pricestats[0]=200;

        data[16].companyname="tissot";
        data[16].pricestats[0]=220;

        data[18].companyname="facebook";
        data[18].pricestats[0]=250;

        data[20].companyname="youtube";
        data[20].pricestats[0]=270;

        data[22].companyname="apple";
        data[22].pricestats[0]=300;

        data[24].companyname="google";
        data[24].pricestats[0]=350;

        data[25].companyname="Ducati";
        data[25].pricestats[0]=400;

        data[27].companyname="Harley Davidson";
        data[27].pricestats[0]=450;

    char a;

    if(property[position]==0 && property2[position]==0 && data[position - 1].showstats!=10)
    {fcallcheck=1;
        display_info(position);
        cout<<"Would you like to buy a stakehold in the company ?\t Enter y or n "<<endl;
        cin>>a;
        if(a=='y')
        {
           //switch cases for each value of r
            if(balance - data[position - 1].pricestats[0] > 0)
            {

            balance = balance - data[position - 1].pricestats[0];

            property[position]++;
            cout<<"Bank Balance has become "<<balance<<endl;
            buycheck=1;
            }
            else
                cout<<"Insufficient Balance to buy property "<<endl;
        }
        else
        {
            cout<<" Property not bought "<<endl;
        }
    }

}

void buy_property_4(int &balance, int *p1, int * p2, int* p3, int* p4 , const int &position, int &buycheck,int &fcallcheck)//property buying function for 4 players
{

    companydata data[28];

    for(int i=0;i<28;i++)
    {
    data[i].showstats=0;
    }

     data[0].showstats=10;//assigning the non buyable places to 10
    data[3].showstats=10;
    data[5].showstats=10;
    data[7].showstats=10;
    data[10].showstats=10;
    data[12].showstats=10;
    data[14].showstats=10;
    data[17].showstats=10;
    data[19].showstats = 10;  //remember waterworks
    data[21].showstats=10;
    data[23].showstats=10;
    data[26].showstats=10;


        data[1].companyname="ferrari";
        data[1].pricestats[0]=60;
        data[1].intereststats[0]=10;
        data[1].pricestats[1]=70;
        data[1].pricestats[2]=150;
        data[1].pricestats[3]=200;
        data[1].intereststats[1]=50;
        data[1].intereststats[2]=100;
        data[1].intereststats[3]=300;

        data[2].companyname="audi";
        data[2].pricestats[0]=70;
        data[2].pricestats[1]=70;data[2].pricestats[2]=150;
        data[2].pricestats[3]=200;
        data[2].intereststats[0]=10;
        data[2].intereststats[1]=60;data[2].intereststats[2]=150;
        data[2].intereststats[3]=350;

        data[4].companyname="pizzahut";
        data[4].pricestats[0]=80;
        data[4].pricestats[1]=80;
        data[4].pricestats[2]=200;
        data[4].pricestats[3]=300;
        data[4].intereststats[0]=15;
        data[4].intereststats[1]=70;
        data[4].intereststats[2]=150;
        data[4].intereststats[3]=350;

        data[6].companyname="tacobell";
        data[6].pricestats[0]=100;
        data[6].pricestats[1]=80;
        data[6].pricestats[2]=200;
        data[6].pricestats[3]=300;
        data[6].intereststats[0]=15;
        data[6].intereststats[1]=80;data[6].intereststats[2]=200;
        data[6].intereststats[3]=400;

        data[8].companyname="pringles";
        data[8].pricestats[0]=120;
        data[8].pricestats[1]=100;
        data[8].pricestats[2]=200;
        data[8].pricestats[3]=350;
        data[8].intereststats[0]=20;
        data[8].intereststats[1]=100;
        data[8].intereststats[2]=200;
        data[8].intereststats[3]=450;

        data[9].companyname="lays";
        data[9].pricestats[0]=140;
        data[9].pricestats[1]=100;
        data[9].pricestats[2]=200;
        data[9].pricestats[3]=350;
        data[9].intereststats[0]=20;
        data[9].intereststats[1]=100;
        data[9].intereststats[2]=250;
        data[9].intereststats[3]=500;

        data[11].companyname="Versace";
        data[11].pricestats[0]=150;
        data[11].pricestats[1]=120;
        data[11].pricestats[2]=250;
        data[11].pricestats[3]=420;
        data[11].intereststats[0]=25;
        data[11].intereststats[1]=110;
        data[11].intereststats[2]=250;
        data[11].intereststats[3]=600;

        data[13].companyname="Tommy Hilfiger";
        data[13].pricestats[0]=180;
        data[13].pricestats[1]=150;
        data[13].pricestats[2]=250;
        data[13].pricestats[3]=450;
        data[13].intereststats[0]=25;
        data[13].intereststats[1]=110;
        data[13].intereststats[2]=300;
        data[13].intereststats[3]=650;

        data[15].companyname="rolex";
        data[15].pricestats[0]=200;
        data[15].pricestats[1]=150;
        data[15].pricestats[2]=300;
        data[15].pricestats[3]=550;
        data[15].intereststats[0]=30;
        data[15].intereststats[1]=120;
        data[15].intereststats[2]=300;
        data[15].intereststats[3]=700;

        data[16].companyname="tissot";
        data[16].pricestats[0]=220;
        data[16].pricestats[1]=150;
        data[16].pricestats[2]=300;
        data[16].pricestats[3]=550;
        data[16].intereststats[0]=35;
        data[16].intereststats[1]=120;
        data[16].intereststats[2]=350;
        data[16].intereststats[3]=800;

        data[18].companyname="facebook";
        data[18].pricestats[0]=250;
        data[18].pricestats[1]=200;
        data[18].pricestats[2]=350;
        data[18].pricestats[3]=650;
        data[18].intereststats[0]=50;
        data[18].intereststats[1]=150;
        data[18].intereststats[2]=350;
        data[18].intereststats[3]=900;

        data[20].companyname="youtube";
        data[20].pricestats[0]=270;
        data[20].pricestats[1]=200;
        data[20].pricestats[2]=350;
        data[20].pricestats[3]=650;
        data[20].intereststats[0]=60;
        data[20].intereststats[1]=200;
        data[20].intereststats[2]=400;
        data[20].intereststats[3]=1000;

        data[22].companyname="apple";
        data[22].pricestats[0]=300;
        data[22].pricestats[1]=250;
        data[22].pricestats[2]=450;
        data[22].pricestats[3]=750;
        data[22].intereststats[0]=80;
        data[22].intereststats[1]=250;
        data[22].intereststats[2]=500;
        data[22].intereststats[3]=1100;

        data[24].companyname="google";
        data[24].pricestats[0]=350;
        data[24].pricestats[1]=250;
        data[24].pricestats[2]=400;
        data[24].pricestats[3]=750;
        data[24].intereststats[0]=90;
        data[24].intereststats[1]=300;
        data[24].intereststats[2]=600;
        data[24].intereststats[3]=1200;

        data[25].companyname="Ducati";
        data[25].pricestats[0]=400;
        data[25].pricestats[1]=300;
        data[25].pricestats[2]=500;
        data[25].pricestats[3]=900;
        data[25].intereststats[0]=100;
        data[25].intereststats[1]=350;
        data[25].intereststats[2]=700;
        data[25].intereststats[3]=1300;

        data[27].companyname="Harley Davidson";
        data[27].pricestats[0]=450;
        data[27].pricestats[1]=300;
        data[27].pricestats[2]=500;
        data[27].pricestats[3]=900;
        data[27].intereststats[0]=150;
        data[27].intereststats[1]=400;
        data[27].intereststats[2]=800;
        data[27].intereststats[3]=1500;

        char a;
        if(p1[position]==0 && p2[position]==0 && p3[position] == 0 && p4[position]==0 && data[position - 1].showstats != 10)
        {      fcallcheck=1;
            display_info(position);
        cout<<"Would you like to buy a stakehold in the company ?\t Enter y or n "<<endl;
        cin>>a;
        if(a=='y')
        {
           //switch cases for each value of r
            if(balance - data[position - 1].pricestats[0] > 0)
            {balance = balance - data[position - 1].pricestats[0];

            p1[position]++;
            cout<<"Bank Balance has become "<<balance<<endl;
            buycheck=1;
            }
            else
            {
                cout<<"Insufficient Balance to buy property "<<endl;
            }
        }
        else
        {
            cout<<"Property not bought "<<endl;
        }
        }


}

void buy_share(int &balance , int* property , const int &position)//a function for upgrading the shares owned in a company
{


    companydata data[28];

    for(int i=0;i<28;i++)
    {
    data[i].showstats=0;
    }

         data[0].showstats=10;//assigning the non buyable places to 10
    data[3].showstats=10;
    data[5].showstats=10;
    data[7].showstats=10;
    data[10].showstats=10;
    data[12].showstats=10;
    data[14].showstats=10;
    data[17].showstats=10;
    data[19].showstats = 10;  //remember waterworks
    data[21].showstats=10;
    data[23].showstats=10;
    data[26].showstats=10;

        data[1].companyname="ferrari";
        data[1].pricestats[0]=60;
        data[1].intereststats[0]=10;
        data[1].pricestats[1]=70;
        data[1].pricestats[2]=150;
        data[1].pricestats[3]=200;
        data[1].intereststats[1]=50;
        data[1].intereststats[2]=100;
        data[1].intereststats[3]=300;

        data[2].companyname="audi";
        data[2].pricestats[0]=70;
        data[2].pricestats[1]=70;data[2].pricestats[2]=150;
        data[2].pricestats[3]=200;
        data[2].intereststats[0]=10;
        data[2].intereststats[1]=60;data[2].intereststats[2]=150;
        data[2].intereststats[3]=350;

        data[4].companyname="pizzahut";
        data[4].pricestats[0]=80;
        data[4].pricestats[1]=80;
        data[4].pricestats[2]=200;
        data[4].pricestats[3]=300;
        data[4].intereststats[0]=15;
        data[4].intereststats[1]=70;
        data[4].intereststats[2]=150;
        data[4].intereststats[3]=350;

        data[6].companyname="tacobell";
        data[6].pricestats[0]=100;
        data[6].pricestats[1]=80;
        data[6].pricestats[2]=200;
        data[6].pricestats[3]=300;
        data[6].intereststats[0]=15;
        data[6].intereststats[1]=80;data[6].intereststats[2]=200;
        data[6].intereststats[3]=400;

        data[8].companyname="pringles";
        data[8].pricestats[0]=120;
        data[8].pricestats[1]=100;
        data[8].pricestats[2]=200;
        data[8].pricestats[3]=350;
        data[8].intereststats[0]=20;
        data[8].intereststats[1]=100;
        data[8].intereststats[2]=200;
        data[8].intereststats[3]=450;

        data[9].companyname="lays";
        data[9].pricestats[0]=140;
        data[9].pricestats[1]=100;
        data[9].pricestats[2]=200;
        data[9].pricestats[3]=350;
        data[9].intereststats[0]=20;
        data[9].intereststats[1]=100;
        data[9].intereststats[2]=250;
        data[9].intereststats[3]=500;

        data[11].companyname="Versace";
        data[11].pricestats[0]=150;
        data[11].pricestats[1]=120;
        data[11].pricestats[2]=250;
        data[11].pricestats[3]=420;
        data[11].intereststats[0]=25;
        data[11].intereststats[1]=110;
        data[11].intereststats[2]=250;
        data[11].intereststats[3]=600;

        data[13].companyname="Tommy Hilfiger";
        data[13].pricestats[0]=180;
        data[13].pricestats[1]=150;
        data[13].pricestats[2]=250;
        data[13].pricestats[3]=450;
        data[13].intereststats[0]=25;
        data[13].intereststats[1]=110;
        data[13].intereststats[2]=300;
        data[13].intereststats[3]=650;

        data[15].companyname="rolex";
        data[15].pricestats[0]=200;
        data[15].pricestats[1]=150;
        data[15].pricestats[2]=300;
        data[15].pricestats[3]=550;
        data[15].intereststats[0]=30;
        data[15].intereststats[1]=120;
        data[15].intereststats[2]=300;
        data[15].intereststats[3]=700;

        data[16].companyname="tissot";
        data[16].pricestats[0]=220;
        data[16].pricestats[1]=150;
        data[16].pricestats[2]=300;
        data[16].pricestats[3]=550;
        data[16].intereststats[0]=35;
        data[16].intereststats[1]=120;
        data[16].intereststats[2]=350;
        data[16].intereststats[3]=800;

        data[18].companyname="facebook";
        data[18].pricestats[0]=250;
        data[18].pricestats[1]=200;
        data[18].pricestats[2]=350;
        data[18].pricestats[3]=650;
        data[18].intereststats[0]=50;
        data[18].intereststats[1]=150;
        data[18].intereststats[2]=350;
        data[18].intereststats[3]=900;

        data[20].companyname="youtube";
        data[20].pricestats[0]=270;
        data[20].pricestats[1]=200;
        data[20].pricestats[2]=350;
        data[20].pricestats[3]=650;
        data[20].intereststats[0]=60;
        data[20].intereststats[1]=200;
        data[20].intereststats[2]=400;
        data[20].intereststats[3]=1000;

        data[22].companyname="apple";
        data[22].pricestats[0]=300;
        data[22].pricestats[1]=250;
        data[22].pricestats[2]=450;
        data[22].pricestats[3]=750;
        data[22].intereststats[0]=80;
        data[22].intereststats[1]=250;
        data[22].intereststats[2]=500;
        data[22].intereststats[3]=1100;

        data[24].companyname="google";
        data[24].pricestats[0]=350;
        data[24].pricestats[1]=250;
        data[24].pricestats[2]=400;
        data[24].pricestats[3]=750;
        data[24].intereststats[0]=90;
        data[24].intereststats[1]=300;
        data[24].intereststats[2]=600;
        data[24].intereststats[3]=1200;

        data[25].companyname="Ducati";
        data[25].pricestats[0]=400;
        data[25].pricestats[1]=300;
        data[25].pricestats[2]=500;
        data[25].pricestats[3]=900;
        data[25].intereststats[0]=100;
        data[25].intereststats[1]=350;
        data[25].intereststats[2]=700;
        data[25].intereststats[3]=1300;

        data[27].companyname="Harley Davidson";
        data[27].pricestats[0]=450;
        data[27].pricestats[1]=300;
        data[27].pricestats[2]=500;
        data[27].pricestats[3]=900;
        data[27].intereststats[0]=150;
        data[27].intereststats[1]=400;
        data[27].intereststats[2]=800;
        data[27].intereststats[3]=1500;


    if(property[position]!=0)//checks if the property is bought by the player
    {
        char a;
        display_info(position);
        cout<<"Would you like to upgrade your share stake in the company ? \t Enter y or n "<<endl;
        cin>>a;
        if(a=='y')
        {
            if(balance - data[position - 1].pricestats[property[position]])

            {
                balance = balance - data[position - 1].pricestats[property[position]];
            property[position]++;
            cout<<"Bank Balance has become "<<balance<<endl;
            }
            else
                cout<<"Balance insufficient to buy shares "<<endl;
        }
        else
        {
            cout<<"Share not bought"<<endl;
        }

    }
}


bool check_property (const int* a , const int &r)
{
        bool flag = false;
        if(a[r]!=0)
            flag = true;

        return flag;

}


void pay_rent ( int &balance , int &balance2, int* property , const int &position )
{

 companydata data[28];

    for(int i=0;i<28;i++)
    {
    data[i].showstats=0;
    }

    data[0].showstats=10;//assigning the non buyable places to 10
    data[3].showstats=10;
    data[5].showstats=10;
    data[7].showstats=10;
    data[10].showstats=10;
    data[12].showstats=10;
    data[14].showstats=10;
    data[17].showstats=10;
    data[19].showstats = 10;  //remember waterworks
    data[21].showstats=10;
    data[23].showstats=10;
    data[26].showstats=10;


        data[1].companyname="ferrari";
        data[1].pricestats[0]=60;
        data[1].intereststats[0]=10;
        data[1].pricestats[1]=70;
        data[1].pricestats[2]=150;
        data[1].pricestats[3]=200;
        data[1].intereststats[1]=50;
        data[1].intereststats[2]=100;
        data[1].intereststats[3]=300;

        data[2].companyname="audi";
        data[2].pricestats[0]=70;
        data[2].pricestats[1]=70;data[2].pricestats[2]=150;
        data[2].pricestats[3]=200;
        data[2].intereststats[0]=10;
        data[2].intereststats[1]=60;data[2].intereststats[2]=150;
        data[2].intereststats[3]=350;

        data[4].companyname="pizzahut";
        data[4].pricestats[0]=80;
        data[4].pricestats[1]=80;
        data[4].pricestats[2]=200;
        data[4].pricestats[3]=300;
        data[4].intereststats[0]=15;
        data[4].intereststats[1]=70;
        data[4].intereststats[2]=150;
        data[4].intereststats[3]=350;

        data[6].companyname="tacobell";
        data[6].pricestats[0]=100;
        data[6].pricestats[1]=80;
        data[6].pricestats[2]=200;
        data[6].pricestats[3]=300;
        data[6].intereststats[0]=15;
        data[6].intereststats[1]=80;data[6].intereststats[2]=200;
        data[6].intereststats[3]=400;

        data[8].companyname="pringles";
        data[8].pricestats[0]=120;
        data[8].pricestats[1]=100;
        data[8].pricestats[2]=200;
        data[8].pricestats[3]=350;
        data[8].intereststats[0]=20;
        data[8].intereststats[1]=100;
        data[8].intereststats[2]=200;
        data[8].intereststats[3]=450;

        data[9].companyname="lays";
        data[9].pricestats[0]=140;
        data[9].pricestats[1]=100;
        data[9].pricestats[2]=200;
        data[9].pricestats[3]=350;
        data[9].intereststats[0]=20;
        data[9].intereststats[1]=100;
        data[9].intereststats[2]=250;
        data[9].intereststats[3]=500;

        data[11].companyname="Versace";
        data[11].pricestats[0]=150;
        data[11].pricestats[1]=120;
        data[11].pricestats[2]=250;
        data[11].pricestats[3]=420;
        data[11].intereststats[0]=25;
        data[11].intereststats[1]=110;
        data[11].intereststats[2]=250;
        data[11].intereststats[3]=600;

        data[13].companyname="Tommy Hilfiger";
        data[13].pricestats[0]=180;
        data[13].pricestats[1]=150;
        data[13].pricestats[2]=250;
        data[13].pricestats[3]=450;
        data[13].intereststats[0]=25;
        data[13].intereststats[1]=110;
        data[13].intereststats[2]=300;
        data[13].intereststats[3]=650;

        data[15].companyname="rolex";
        data[15].pricestats[0]=200;
        data[15].pricestats[1]=150;
        data[15].pricestats[2]=300;
        data[15].pricestats[3]=550;
        data[15].intereststats[0]=30;
        data[15].intereststats[1]=120;
        data[15].intereststats[2]=300;
        data[15].intereststats[3]=700;

        data[16].companyname="tissot";
        data[16].pricestats[0]=220;
        data[16].pricestats[1]=150;
        data[16].pricestats[2]=300;
        data[16].pricestats[3]=550;
        data[16].intereststats[0]=35;
        data[16].intereststats[1]=120;
        data[16].intereststats[2]=350;
        data[16].intereststats[3]=800;

        data[18].companyname="facebook";
        data[18].pricestats[0]=250;
        data[18].pricestats[1]=200;
        data[18].pricestats[2]=350;
        data[18].pricestats[3]=650;
        data[18].intereststats[0]=50;
        data[18].intereststats[1]=150;
        data[18].intereststats[2]=350;
        data[18].intereststats[3]=900;

        data[20].companyname="youtube";
        data[20].pricestats[0]=270;
        data[20].pricestats[1]=200;
        data[20].pricestats[2]=350;
        data[20].pricestats[3]=650;
        data[20].intereststats[0]=60;
        data[20].intereststats[1]=200;
        data[20].intereststats[2]=400;
        data[20].intereststats[3]=1000;

        data[22].companyname="apple";
        data[22].pricestats[0]=300;
        data[22].pricestats[1]=250;
        data[22].pricestats[2]=450;
        data[22].pricestats[3]=750;
        data[22].intereststats[0]=80;
        data[22].intereststats[1]=250;
        data[22].intereststats[2]=500;
        data[22].intereststats[3]=1100;

        data[24].companyname="google";
        data[24].pricestats[0]=350;
        data[24].pricestats[1]=250;
        data[24].pricestats[2]=400;
        data[24].pricestats[3]=750;
        data[24].intereststats[0]=90;
        data[24].intereststats[1]=300;
        data[24].intereststats[2]=600;
        data[24].intereststats[3]=1200;

        data[25].companyname="Ducati";
        data[25].pricestats[0]=400;
        data[25].pricestats[1]=300;
        data[25].pricestats[2]=500;
        data[25].pricestats[3]=900;
        data[25].intereststats[0]=100;
        data[25].intereststats[1]=350;
        data[25].intereststats[2]=700;
        data[25].intereststats[3]=1300;

        data[27].companyname="Harley Davidson";
        data[27].pricestats[0]=450;
        data[27].pricestats[1]=300;
        data[27].pricestats[2]=500;
        data[27].pricestats[3]=900;
        data[27].intereststats[0]=150;
        data[27].intereststats[1]=400;
        data[27].intereststats[2]=800;
        data[27].intereststats[3]=1500;


    if (check_property(property,position))
    {
        // switch cases for different values of a and r
        display_info(position);
        cout<<"You are required to pay rent to the other player"<<endl;
        balance = balance - data[position - 1].intereststats[property[position] - 1] ;
        cout<<"Bank Balance has become "<<balance<<endl;
        balance2 = balance2 + data[position - 1].intereststats[property[position] - 1] ;
        cout<<"Bank Balance of the other player has become "<<balance2<<endl;
    }
}

void pay_rent_4 ( int &balance , int &balance2, int &balance3, int &balance4 ,int* property , int* property2, int* property3, int*property4 , const int &position )
{

 companydata data[28];

    for(int i=0;i<28;i++)
    {
    data[i].showstats=0;
    }

    data[0].showstats=10;//assigning the non buyable places to 10
    data[3].showstats=10;
    data[5].showstats=10;
    data[7].showstats=10;
    data[10].showstats=10;
    data[12].showstats=10;
    data[14].showstats=10;
    data[17].showstats=10;
    data[19].showstats = 10;
    data[21].showstats=10;
    data[23].showstats=10;
    data[26].showstats=10;


        data[1].companyname="ferrari";
        data[1].pricestats[0]=60;
        data[1].intereststats[0]=10;
        data[1].pricestats[1]=70;
        data[1].pricestats[2]=150;
        data[1].pricestats[3]=200;
        data[1].intereststats[1]=50;
        data[1].intereststats[2]=100;
        data[1].intereststats[3]=300;

        data[2].companyname="audi";
        data[2].pricestats[0]=70;
        data[2].pricestats[1]=70;data[2].pricestats[2]=150;
        data[2].pricestats[3]=200;
        data[2].intereststats[0]=10;
        data[2].intereststats[1]=60;data[2].intereststats[2]=150;
        data[2].intereststats[3]=350;

        data[4].companyname="pizzahut";
        data[4].pricestats[0]=80;
        data[4].pricestats[1]=80;
        data[4].pricestats[2]=200;
        data[4].pricestats[3]=300;
        data[4].intereststats[0]=15;
        data[4].intereststats[1]=70;
        data[4].intereststats[2]=150;
        data[4].intereststats[3]=350;

        data[6].companyname="tacobell";
        data[6].pricestats[0]=100;
        data[6].pricestats[1]=80;
        data[6].pricestats[2]=200;
        data[6].pricestats[3]=300;
        data[6].intereststats[0]=15;
        data[6].intereststats[1]=80;data[6].intereststats[2]=200;
        data[6].intereststats[3]=400;

        data[8].companyname="pringles";
        data[8].pricestats[0]=120;
        data[8].pricestats[1]=100;
        data[8].pricestats[2]=200;
        data[8].pricestats[3]=350;
        data[8].intereststats[0]=20;
        data[8].intereststats[1]=100;
        data[8].intereststats[2]=200;
        data[8].intereststats[3]=450;

        data[9].companyname="lays";
        data[9].pricestats[0]=140;
        data[9].pricestats[1]=100;
        data[9].pricestats[2]=200;
        data[9].pricestats[3]=350;
        data[9].intereststats[0]=20;
        data[9].intereststats[1]=100;
        data[9].intereststats[2]=250;
        data[9].intereststats[3]=500;

        data[11].companyname="Versace";
        data[11].pricestats[0]=150;
        data[11].pricestats[1]=120;
        data[11].pricestats[2]=250;
        data[11].pricestats[3]=420;
        data[11].intereststats[0]=25;
        data[11].intereststats[1]=110;
        data[11].intereststats[2]=250;
        data[11].intereststats[3]=600;

        data[13].companyname="Tommy Hilfiger";
        data[13].pricestats[0]=180;
        data[13].pricestats[1]=150;
        data[13].pricestats[2]=250;
        data[13].pricestats[3]=450;
        data[13].intereststats[0]=25;
        data[13].intereststats[1]=110;
        data[13].intereststats[2]=300;
        data[13].intereststats[3]=650;

        data[15].companyname="rolex";
        data[15].pricestats[0]=200;
        data[15].pricestats[1]=150;
        data[15].pricestats[2]=300;
        data[15].pricestats[3]=550;
        data[15].intereststats[0]=30;
        data[15].intereststats[1]=120;
        data[15].intereststats[2]=300;
        data[15].intereststats[3]=700;

        data[16].companyname="tissot";
        data[16].pricestats[0]=220;
        data[16].pricestats[1]=150;
        data[16].pricestats[2]=300;
        data[16].pricestats[3]=550;
        data[16].intereststats[0]=35;
        data[16].intereststats[1]=120;
        data[16].intereststats[2]=350;
        data[16].intereststats[3]=800;

        data[18].companyname="facebook";
        data[18].pricestats[0]=250;
        data[18].pricestats[1]=200;
        data[18].pricestats[2]=350;
        data[18].pricestats[3]=650;
        data[18].intereststats[0]=50;
        data[18].intereststats[1]=150;
        data[18].intereststats[2]=350;
        data[18].intereststats[3]=900;

        data[20].companyname="youtube";
        data[20].pricestats[0]=270;
        data[20].pricestats[1]=200;
        data[20].pricestats[2]=350;
        data[20].pricestats[3]=650;
        data[20].intereststats[0]=60;
        data[20].intereststats[1]=200;
        data[20].intereststats[2]=400;
        data[20].intereststats[3]=1000;

        data[22].companyname="apple";
        data[22].pricestats[0]=300;
        data[22].pricestats[1]=250;
        data[22].pricestats[2]=450;
        data[22].pricestats[3]=750;
        data[22].intereststats[0]=80;
        data[22].intereststats[1]=250;
        data[22].intereststats[2]=500;
        data[22].intereststats[3]=1100;

        data[24].companyname="google";
        data[24].pricestats[0]=350;
        data[24].pricestats[1]=250;
        data[24].pricestats[2]=400;
        data[24].pricestats[3]=750;
        data[24].intereststats[0]=90;
        data[24].intereststats[1]=300;
        data[24].intereststats[2]=600;
        data[24].intereststats[3]=1200;

        data[25].companyname="Ducati";
        data[25].pricestats[0]=400;
        data[25].pricestats[1]=300;
        data[25].pricestats[2]=500;
        data[25].pricestats[3]=900;
        data[25].intereststats[0]=100;
        data[25].intereststats[1]=350;
        data[25].intereststats[2]=700;
        data[25].intereststats[3]=1300;

        data[27].companyname="Harley Davidson";
        data[27].pricestats[0]=450;
        data[27].pricestats[1]=300;
        data[27].pricestats[2]=500;
        data[27].pricestats[3]=900;
        data[27].intereststats[0]=150;
        data[27].intereststats[1]=400;
        data[27].intereststats[2]=800;
        data[27].intereststats[3]=1500;

    if (check_property(property2,position))
    {
        // switch cases for different values of a and r
        display_info(position);
        cout<<"You are required to pay rent to the other player"<<endl;
        balance = balance - data[position - 1].intereststats[property2[position] - 1] ;
        cout<<"Bank Balance has become "<<balance<<endl;
        balance2 = balance2 + data[position - 1].intereststats[property2[position] - 1] ;
        cout<<"Bank Balance of the other player has become "<<balance2<<endl;
    }
    if (check_property(property3,position))
    {
        // switch cases for different values of a and r
        display_info(position);
        cout<<"You are required to pay rent to the other player"<<endl;
        balance = balance - data[position - 1].intereststats[property3[position] - 1] ;
        cout<<"Bank Balance has become "<<balance<<endl;
        balance3 = balance3 + data[position - 1].intereststats[property3[position] - 1] ;
        cout<<"Bank Balance of the other player has become "<<balance3<<endl;
    }
    if (check_property(property4,position))
    {
        // switch cases for different values of a and r
        display_info(position);
        cout<<"You are required to pay rent to the other player"<<endl;
        balance = balance - data[position - 1].intereststats[property4[position] - 1] ;
        cout<<"Bank Balance has become "<<balance<<endl;
        balance4 = balance4 + data[position - 1].intereststats[property4[position] - 1] ;
        cout<<"Bank Balance of the other player has become "<<balance4<<endl;
    }
}


void Jail(int &bankbalance,int position_current)//Displays if player landed on JAil and recduces the bankbalance accordingly
{
    if(position_current==8)
    {
        bankbalance=bankbalance-150;
        cout<<endl<<"You Have Gone to Jail. $150 have been spent to come out"<<endl;
        cout<<"Balance has now become "<<bankbalance<<endl;
    }
}
int sum_dice()//user has to enter 1 to roll dice

{
int d1p1,d2p1,sum1=0;

time_t t;
time(&t);
std::srand((unsigned int) t);

int r;
cout<<"Enter 1 to roll dice . Entering another integer skips the turn "<<endl;
cin >>r;
if(r==1)
{
d1p1=(rand()%(6)+1);
d2p1=(rand()%(6)+1);
sum1=d1p1+d2p1;
cout<<" Your dice numbers are "<<d1p1<<"  and  "<<d2p1<<endl;
return sum1;
}

if(r!=1)
    {
        cout<<"\n Invalid Input, Chance Skipped \n";
        return 0;
    }

}
void drawrecnew(Rectangle *z , playerinfo*info3,int j3,int n)//for drawing rectangle on properties that are owned by the player
{
    for(int i=0; i<29 ;i++)
    {
        if(info3[j3-1].properties[i]==1)
        {
            z[i-1].show();
        }
    }
}

void token_move(Circle &c , int &position_current , int dice_number , int &balance)
{
    int n = position_current;
    if(n + dice_number<=28)
    {

        while(position_current<n+dice_number)
    {
        if(position_current<=7)//movement of token from bottom right to bottom left
        {
            for(int i=0;i<72;i++)
            {
                c.move(-1,0);
                wait(0.0001);

            }
            position_current++ ;
        }

        if(position_current>7 && position_current<=14)//Movement of token from bottom left to top left
        {
            if(n+dice_number==8)
            {
                break;
            }
            for(int i=0;i<72;i++)
            {
                c.move(0,-1);
                wait(0.0001);

            }
             position_current++ ;
        }
        if(position_current>14 && position_current<=21)//movement of token from top left to top right
        {

            if(n+dice_number==15)//Anticlockwise movement of token when landed on REBOUND i.e, square 15
            {
                Rectangle RE(310,260,120,20);
                RE.setColor(COLOR(255,0,0));
                RE.setFill(true);
                Text t(310,260,"REBOUND!!");
                while(position_current>n-dice_number)
                {
                  if(position_current>8 && position_current<=15)
                    {
                        if(n-dice_number==8)
                        {
                            break;
                        }
                            for(int i=0;i<73;i++)
                            {
                            c.move(0,1);
                            wait(0.0001);

                            }
                            position_current-- ;
                    }
                  if(position_current<=8&&position_current>1)
                    {
                        for(int i=0;i<72;i++)
                        {
                        c.move(1,0);
                        wait(0.0001);

                        }
                        position_current-- ;
                    }
                   if(position_current<=1 && position_current>-6)
                   {

                        if(n-dice_number==1)
                        {
                            break;
                        }
                        for(int i=0;i<72;i++)

                        {
                            c.move(0,-1);
                            wait(0.0001);
                        }
                        position_current--;
                    }
                    if(position_current<=-6 && position_current>-13)
                    {
                        if(n-dice_number==-6)
                        {
                            break;
                        }
                        for(int i=0;i<72;i++)
                        {
                            c.move(-1,0);
                            wait(0.0001);
                        }
                        position_current --;
                    }

                }
                   if(position_current!=0)
                   {
                       position_current = (position_current + 28)%28 ;
                   }
                   else
                    position_current = 28;

                   break;

            }
            for(int i=0;i<72;i++)
            {
                c.move(1,0);
                wait(0.0001);

            }
              position_current++;
        }
        if(position_current>21 && position_current<=28)//movement of token from top right to bottom right
        {
            if(n+dice_number==22)//movement of token to JAIL i.e,square 8 when landed on  GOING TO JAIL i.e, square 22
            {
                Rectangle r(310,260,120,20);
                r.setColor(COLOR(255,0,0));
                r.setFill(true);
                Text t(310,260,"GOING TO JAIL !");
                for(int i=0;i<504;i++)
                {
                    c.move(0,1);
                    wait(0.0001);
                }
                for(int i=0;i<504;i++)
                {
                    c.move(-1,0);
                    wait(0.0001);

                }
                position_current = 8;
                break;
            }
            for(int i=0;i<73;i++)
            {
                c.move(0,1);
                wait(0.0001);

            }
             position_current++;
        }
    }
    }
    else
    {
    while(position_current<n+dice_number)
    {
        if(position_current>14 && position_current<=21)
        {
            for(int i=0;i<71;i++)
            {
                c.move(1,0);
                wait(0.0001);

            }
              position_current++;
        }
        if(position_current>21 && position_current<=28)
        {
            for(int i=0;i<72;i++)
            {
                c.move(0,1);
                wait(0.0001);

            }
             position_current++;
        }

        if(position_current>28&& position_current<=35)
        {
            if(n+dice_number==29)
            {
                break;
            }
            for(int i=0;i<72;i++)
            {
                c.move(-1,0);
                wait(0.0001);

            }
             position_current++ ;
        }
        if(position_current>35&&position_current<=42)
        {
            if(n+dice_number==36)
            {
                break;
            }
            for(int i=0 ; i<71;i++)
            {
                c.move(0,-1);
                wait(0.0001);
            }
            position_current++;
        }
    }
    position_current = position_current%28;//mainting current position value lessthan or equal to 28
    cout<<"Player receives $200 for landing on or passing go"<<endl;
    balance +=200;
    cout<<"Balance has now become "<<balance<<endl;
    }

}

void lottery(int &balance,const int &position)
{
    if(position== 6 || position == 13||position==27 )
    {
        time_t t;
        time(&t);
        std::srand((unsigned int) t);
        int n = rand()%10 + 1;//generating a random number between 1 to 10 for Lottery game
        cout<<"Welcome to Lottery Game .\n Guess a number from 1 to 10 \n If you guess the number what the computer guesses, you win a huge prize !\n ";
        cout<<"You will have to bet $100 for this.\n Would you like to play the game? Enter y or n"<<endl;
        char in;
        cin>>in;
        int input;
        if(in=='y')
        {
            if(balance > 100)

            {
                cout<<"Enter the input number "<<endl;
            cin>>input;
            cout<<"Your number - "<<input<<endl;
            cout<<"Computer's random number - "<<n<<endl;
            if(input==n)
            {
                cout<<"Congratulations ! ";
                balance = balance + 100*n;
                cout<<"Balance has now become "<<balance<<endl;
            }
            else
            {
                cout<<"Hard luck !!";
                balance = balance - 100;
                cout<<"Balance has now become "<<balance<<endl;
            }
        }
    }
        else
            cout<<"Lottery not played "<<endl;
    }
}

int chance_number()// random chancenumber used for picking a card from among 8 cards in chance function
{
    time_t t;
    time(&t);
    std::srand((unsigned int) t);
    int c = rand()%8 + 1;
    return c;
}

void chance_show(int n, int &bankbalance)//Picks a random card from 8 cards ,displays it to the player and changes the bankbalance accordingly
{
    int p;
    cout<<"YOU HAVE LANDED ON CHANCE ,PRESS 3 TO PICK A CARD"<<endl;
    cin>>p;
    if(p==3)
    {
        switch(n)
        {
        case 1:
            MessageBox(NULL,"Fire in Godown , $100 LOSS","Chance Card 1",MB_OK);
            bankbalance=bankbalance-100;
            cout<<"Balance has now become "<<bankbalance<<endl;
            break;
        case 2:
            MessageBox(NULL,"Got a Discount Coupon of $100 on an  Online site","Chance Card 2",MB_OK);
            bankbalance=bankbalance+100;
            cout<<"Balance has now become "<<bankbalance<<endl;
            break;
        case 3:
            MessageBox(NULL,"You Had to Pay $200 For Health Insurance","Chance Card 3",MB_OK);
            bankbalance=bankbalance-200;
            cout<<"Balance has now become "<<bankbalance<<endl;
            break;
        case 4:
            MessageBox(NULL,"Your Goods Sold Out Heavily During Festive Season \n             PROFIT of $150","Chance Card 4",MB_OK);
            bankbalance=bankbalance+150;
            cout<<"Balance has now become "<<bankbalance<<endl;
            break;
        case 5:
            MessageBox(NULL,"You Suffered an ACCIDENT And Medical Expenses Were $50  ","Chance Card 5",MB_OK);
            bankbalance=bankbalance-50;
            cout<<"Balance has now become "<<bankbalance<<endl;
            break;
        case 6:
            MessageBox(NULL,"Found A $100 Note While Walking in the Street","Chance Card 6",MB_OK);
            bankbalance=bankbalance+100;
            cout<<"Balance has now become "<<bankbalance<<endl;
            break;
        case 7:
            MessageBox(NULL,"Relatives Birthday, Pay 100$ for the PARTY","Chance Card 7",MB_OK);
            bankbalance=bankbalance-100;
            cout<<"Balance has now become "<<bankbalance<<endl;
            break;
        case 8:
            MessageBox(NULL,"BONUS!! You get $200","Chance Card 8",MB_OK);
            bankbalance=bankbalance+200;
            cout<<"Balance has now become "<<bankbalance<<endl;
            break;
        }
    }
}



void Chance_Card(int &position_current, int &bankbalance)//calls the chance_show function when landed on CHANCE in the board
{
    if(position_current==18||position_current==24||position_current==11||position_current==4||position_current==20)
    {
        chance_show(chance_number(), bankbalance);
    }
}

void show_info(playerinfo n)//shows player his account information
{
    char s;
    cout<<"Do you want to see your account information?\n  Enter y or n ";
    cin>>s;

    companydata data[28];

        data[1].companyname="Ferrari";
        data[2].companyname="Audi";
        data[4].companyname="Pizza Hut";
        data[6].companyname="Tacobell";
        data[8].companyname="Pringles";
        data[9].companyname="Lays";
        data[11].companyname="Versace";
        data[13].companyname="Tommy Hilfiger";
        data[15].companyname="Rolex";
        data[16].companyname="Tissot";
        data[18].companyname="Facebook";
        data[20].companyname="Youtube";
        data[22].companyname="Apple";
        data[24].companyname="Google";
        data[25].companyname="Ducati";
        data[27].companyname="Harley Davidson";

    if(s=='y')
    {
        cout<<"Balance is "<<n.bankbalance<<endl;
        cout<<"Current square on board is "<<n.position_current<<endl;
        cout<<"Properties owned are - \n";
        for(int i=0;i<29;i++)
        {
            if(n.properties[i] !=0)
            {
                cout<<data[i-1].companyname<<endl;
            }
        }
    }
    else{ cout << "\nInformation not shown\n"; }
}

int main()
{
    initCanvas("Monopoly",620,620);
    beginFrame();
    Rectangle   s1(50,50,100,100),r12(135,50,70,100),r13(205,50,70,100),r14(275,50,70,100),
                r15(345,50,70,100),r16(415,50,70,100),r17(485,50,70,100),s2(570,50,100,100),
                r22(570,135,100,70),r32(570,205,100,70),r42(570,275,100,70),r52(570,345,100,70),
                r62(570,415,100,70),r72(570,485,100,70),s3(570,570,100,100),r222(135,570,70,100),
                r23(205,570,70,100),r24(275,570,70,100),r25(345,570,70,100),r26(415,570,70,100),
                r27(485,570,70,100),s4(50,570,100,100),r21(50,135,100,70),r31(50,205,100,70),
                r41(50,275,100,70),r51(50,345,100,70),r61(50,415,100,70),r71(50,485,100,70),r50(310,310,100,40);
    //Rectangle which form the board
    s1.setFill(true);
    s1.setColor(COLOR(255,0,0));
      Text      t1(50,50,"REBOUND"),t12(135,35,"Rolex"),t120(135,55,"$200"),t13(205,35,"Tissot"),t130(205,55,"$220"),t14(275,50,"CHANCE"),
                t15(345,35,"Facebook"),t150(345,55,"$250"),t16(415,50,"CHANCE"), t17(485,35,"Youtube"),t170(485,55,"$270"),t2(570,50,"Go To Jail"),
                t50(40,115,"Tommy"), t51(40,135,"Hilfiger"),t510(40,155,"$180"), t52(40,205,"LOTTERY"),t53(40,265,"Versace"),t530(40,285,"$150"),t54(40,345,"CHANCE"),
                t55(40,405,"Lays"),t550(40,425,"$140"), t56(40,475,"Pringles"),t560(40,495,"$120"),  t58(135,560,"Taco"),t59(135,580,"Bell"),t590(135,600,"$100"),
                t60(205,570,"LOTTERY"),t61(275,560,"Pizza"),t62(275,580,"Hut"),t620(275,600,"$80"),t63(345,570,"CHANCE"),
                t65(415,570,"Audi"),t650(415,590,"$70"), t66(485,570,"Ferrari"),t660(485,590,"$60"), t67(570,570,"GO"),t68(580,465,"Harley"),t69(580,485,"Davidson"),t690(580,505,"$450"),
                t70(570,415,"LOTTERY"),t72(580,335,"Ducati"),t720(580,355,"$400"),t73(580,265,"Google"),t730(580,285,"$350"),t74(570,205,"CHANCE"),
                t75(580,125,"Apple"),t750(580,145,"$300"),t76(310,310,"MONOPOLY");
     Line       l1(20,520,20,620),l2(40,520,40,620),l3(60,520,60,620),l4(80,520,80,620);
     Rectangle  J1(50,570,35,15),RE1(50,50,70,15);
     J1.setFill(true);
     J1.setColor(COLOR("red"));
     Text   t57(50,570,"JAIL");
     Rectangle  J2(50,570,35,15);

    Rectangle   a1(90,135,20,70),a2(90,275,20,70),a3(90,415,20,70),a4(90,485,20,70),a5(135,530,70,20),a6(275,530,70,20),
                a7(415,530,70,20),a8(485,530,70,20);

                a1.setColor(COLOR(0,255,255));
                a1.setFill(COLOR(0,255,255));
                a2.setColor(COLOR(0,255,255));
                a2.setFill(COLOR(0,255,255));
                a3.setColor(COLOR(255,0,255));
                a3.setFill(COLOR(255,0,255));
                a4.setColor(COLOR(255,0,255));
                a4.setFill(COLOR(255,0,255));
                a5.setColor(COLOR(255,100,100));
                a5.setFill(COLOR(255,100,100));
                a6.setColor(COLOR(255,100,100));
                a6.setFill(COLOR(255,100,100));
                a7.setColor(COLOR(100,100,255));
                a7.setFill(COLOR(100,100,255));
                a8.setColor(COLOR(100,100,255));
                a8.setFill(COLOR(100,100,255));

     Rectangle  b1(90,135,20,70),b2(90,275,20,70),b3(90,415,20,70),b4(90,485,20,70),b5(135,530,70,20),b6(275,530,70,20),
                b7(415,530,70,20),b8(485,530,70,20);

     Rectangle  sr12(135,90,70,20),sr13(205,90,70,20),sr15(345,90,70,20),sr17(485,90,70,20),
                sr22(530,135,20,70),sr42(530,275,20,70),sr52(530,345,20,70),sr72(530,485,20,70);


               sr12.setFill(true);
               sr12.setColor(COLOR("red"));
               sr13.setFill(true);
               sr13.setColor(COLOR("red"));
               sr15.setFill(true);
               sr15.setColor(COLOR("yellow"));
               sr17.setFill(true);
               sr17.setColor(COLOR("yellow"));
               sr22.setFill(true);
               sr22.setColor(COLOR("green"));
               sr42.setFill(true);
               sr42.setColor(COLOR("green"));
               sr52.setFill(true);
               sr52.setColor(COLOR("blue"));
               sr72.setFill(true);
               sr72.setColor(COLOR("blue"));


    Rectangle    srr12(135,90,70,20),srr13(205,90,70,20),srr15(345,90,70,20),srr17(485,90,70,20),
                srr22(530,135,20,70),srr42(530,275,20,70),srr52(530,345,20,70),srr72(530,485,20,70);


    Rectangle   p1(0,0,0,0),p2(485,550,5,5),p3(415,550,5,5),p4(0,0,0,0),p5(275,550,5,5),p6(0,0,0,0),p7(145,550,5,5),p8(0,0,0,0),p9(70,495,5,5),p10(70,415,5,5),
               p11(0,0,0,0),p12(70,275,5,5),p13(0,0,0,0),p14(70,135,5,5),p15(0,0,0,0),p16(145,70,5,5),p17(205,70,5,5),p18(0,0,0,0),p19(345,70,5,5),p20(0,0,0,0),
               p21(485,70,5,5),p22(0,0,0,0),p23(550,135,5,5),p24(0,0,0,0),p25(550,275,5,5),p26(550,345,5,5),p27(0,0,0,0),p28(550,495,5,5);
    //rectangles used for generating tokens when a property is bought by a player
    p2.hide();
    p3.hide();
    p5.hide();
    p7.hide();
    p9.hide();
    p10.hide();
    p12.hide();
    p14.hide();
    p16.hide();
    p17.hide();
    p19.hide();
    p21.hide();
    p23.hide();
    p25.hide();
    p26.hide();
    p28.hide();

    Rectangle  z[]={p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28};//draws small rectangles if player has bought property
    for(int i=0;i<28 ;i++)
    {
            z[i].setFill(true);
            z[i].setColor(COLOR("green"));
            z[i].hide();
    }
    //in this way rectangles of all colors are drawn on every company and hidden
    //when a player buys a company the corresponding colored rectangle is shown while others remain hidden
    Rectangle  z1[]={p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28};
    for(int i=0; i<28 ;i++)
    {
            z1[i].setFill(true);
            z1[i].setColor(COLOR("red"));
            z1[i].hide();
    }
    Rectangle  z2[]={p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28};
    for(int i=0; i<28 ;i++)
    {
            z2[i].setFill(true);
            z2[i].setColor(COLOR("yellow"));
            z2[i].hide();
    }
    Rectangle  z3[]={p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19,p20,p21,p22,p23,p24,p25,p26,p27,p28};
    for(int i=0; i<28 ;i++)
    {
            z3[i].setFill(true);
            z3[i].setColor(COLOR("blue"));
            z3[i].hide();
    }


            endFrame();
        int no_players;
        cout<<"WELCOME TO MONOPOLY GAME !"<<endl<<endl;
        cout<<"Each player gets $1500 irrespective of the number of players"<<endl<<endl;
        cout<<"Each player starts from GO \n\n";
        cout<<"Last Player standing Wins ! "<<endl<<endl;
        //Display of basic rules

        cout<<"How many players are playing this game? ";
        cin>>no_players;
        companydata data2[28];
        int buycheck=0;
        int fcallcheck=0;

    for(int i=0;i<28;i++)//this companydata object is used for sell function reference especially.all names are in small letters
    {
    data2[i].showstats=0;
    }

    data2[0].showstats=10;//assigning the non buyable places to 10
    data2[3].showstats=10;
    data2[5].showstats=10;
    data2[7].showstats=10;
    data2[10].showstats=10;
    data2[12].showstats=10;
    data2[14].showstats=10;
    data2[17].showstats=10;
    data2[19].showstats = 10;  //remember waterworks
    data2[21].showstats=10;
    data2[23].showstats=10;
    data2[26].showstats=10;


        data2[1].companyname="ferrari";
        data2[1].pricestats[0]=60;
        data2[1].intereststats[0]=10;
        data2[1].pricestats[1]=70;
        data2[1].pricestats[2]=150;
        data2[1].pricestats[3]=200;
        data2[1].intereststats[1]=50;
        data2[1].intereststats[2]=100;
        data2[1].intereststats[3]=300;

        data2[2].companyname="audi";
        data2[2].pricestats[0]=70;
        data2[2].pricestats[1]=70;
        data2[2].pricestats[2]=150;
        data2[2].pricestats[3]=200;
        data2[2].intereststats[0]=10;
        data2[2].intereststats[1]=60;
        data2[2].intereststats[2]=150;
        data2[2].intereststats[3]=350;

        data2[4].companyname="pizzahut";
        data2[4].pricestats[0]=80;
        data2[4].pricestats[1]=80;
        data2[4].pricestats[2]=200;
        data2[4].pricestats[3]=300;
        data2[4].intereststats[0]=15;
        data2[4].intereststats[1]=70;
        data2[4].intereststats[2]=150;
        data2[4].intereststats[3]=350;

        data2[6].companyname="tacobell";
        data2[6].pricestats[0]=100;
        data2[6].pricestats[1]=80;
        data2[6].pricestats[2]=200;
        data2[6].pricestats[3]=300;
        data2[6].intereststats[0]=15;
        data2[6].intereststats[1]=80;
        data2[6].intereststats[2]=200;
        data2[6].intereststats[3]=400;

        data2[8].companyname="pringles";
        data2[8].pricestats[0]=120;
        data2[8].pricestats[1]=100;
        data2[8].pricestats[2]=200;
        data2[8].pricestats[3]=350;
        data2[8].intereststats[0]=20;
        data2[8].intereststats[1]=100;
        data2[8].intereststats[2]=200;
        data2[8].intereststats[3]=450;

        data2[9].companyname="lays";
        data2[9].pricestats[0]=140;
        data2[9].pricestats[1]=100;
        data2[9].pricestats[2]=200;
        data2[9].pricestats[3]=350;
        data2[9].intereststats[0]=20;
        data2[9].intereststats[1]=100;
        data2[9].intereststats[2]=250;
        data2[9].intereststats[3]=500;

        data2[11].companyname="versace";
        data2[11].pricestats[0]=150;
        data2[11].pricestats[1]=120;
        data2[11].pricestats[2]=250;
        data2[11].pricestats[3]=420;
        data2[11].intereststats[0]=25;
        data2[11].intereststats[1]=110;
        data2[11].intereststats[2]=250;
        data2[11].intereststats[3]=600;

        data2[13].companyname="tommyhilfiger";
        data2[13].pricestats[0]=180;
        data2[13].pricestats[1]=150;
        data2[13].pricestats[2]=250;
        data2[13].pricestats[3]=450;
        data2[13].intereststats[0]=25;
        data2[13].intereststats[1]=110;
        data2[13].intereststats[2]=300;
        data2[13].intereststats[3]=650;

        data2[15].companyname="rolex";
        data2[15].pricestats[0]=200;
        data2[15].pricestats[1]=150;
        data2[15].pricestats[2]=300;
        data2[15].pricestats[3]=550;
        data2[15].intereststats[0]=30;
        data2[15].intereststats[1]=120;
        data2[15].intereststats[2]=300;
        data2[15].intereststats[3]=700;

        data2[16].companyname="tissot";
        data2[16].pricestats[0]=220;
        data2[16].pricestats[1]=150;
        data2[16].pricestats[2]=300;
        data2[16].pricestats[3]=550;
        data2[16].intereststats[0]=35;
        data2[16].intereststats[1]=120;
        data2[16].intereststats[2]=350;
        data2[16].intereststats[3]=800;

        data2[18].companyname="facebook";
        data2[18].pricestats[0]=250;
        data2[18].pricestats[1]=200;
        data2[18].pricestats[2]=350;
        data2[18].pricestats[3]=650;
        data2[18].intereststats[0]=50;
        data2[18].intereststats[1]=150;
        data2[18].intereststats[2]=350;
        data2[18].intereststats[3]=900;

        data2[20].companyname="youtube";
        data2[20].pricestats[0]=270;
        data2[20].pricestats[1]=200;
        data2[20].pricestats[2]=350;
        data2[20].pricestats[3]=650;
        data2[20].intereststats[0]=60;
        data2[20].intereststats[1]=200;
        data2[20].intereststats[2]=400;
        data2[20].intereststats[3]=1000;

        data2[22].companyname="apple";
        data2[22].pricestats[0]=300;
        data2[22].pricestats[1]=250;
        data2[22].pricestats[2]=450;
        data2[22].pricestats[3]=750;
        data2[22].intereststats[0]=80;
        data2[22].intereststats[1]=250;
        data2[22].intereststats[2]=500;
        data2[22].intereststats[3]=1100;

        data2[24].companyname="google";
        data2[24].pricestats[0]=350;
        data2[24].pricestats[1]=250;
        data2[24].pricestats[2]=400;
        data2[24].pricestats[3]=750;
        data2[24].intereststats[0]=90;
        data2[24].intereststats[1]=300;
        data2[24].intereststats[2]=600;
        data2[24].intereststats[3]=1200;

        data2[25].companyname="ducati";
        data2[25].pricestats[0]=400;
        data2[25].pricestats[1]=300;
        data2[25].pricestats[2]=500;
        data2[25].pricestats[3]=900;
        data2[25].intereststats[0]=100;
        data2[25].intereststats[1]=350;
        data2[25].intereststats[2]=700;
        data2[25].intereststats[3]=1300;

        data2[27].companyname="harleydavidson";
        data2[27].pricestats[0]=450;
        data2[27].pricestats[1]=300;
        data2[27].pricestats[2]=500;
        data2[27].pricestats[3]=900;
        data2[27].intereststats[0]=150;
        data2[27].intereststats[1]=400;
        data2[27].intereststats[2]=800;
        data2[27].intereststats[3]=1500;
        if(no_players ==2)
        {

        Circle c1(570,570,5);
        Circle c2(570,570,5);
        c1.setFill(true);
        c1.setColor(COLOR("green"));
        c2.setFill(true);
        c2.setColor(COLOR("red"));

        int token =1;
        playerinfo player[2];
        //now we call all the functions in every players turn
        while(true)
        {

        if(token%2 !=0)
        {
            //chance of player 1
            cout<<"\n *****Chance of Player 1 ***** \n"<<endl;
            token_move(c1,player[0].position_current,sum_dice(),player[0].bankbalance);
            Chance_Card(player[0].position_current, player[0].bankbalance);
            balance_check_2(player[0].bankbalance,token);
            lottery(player[0].bankbalance,player[0].position_current);
            balance_check_2(player[0].bankbalance,token);
            Jail(player[0].bankbalance,player[0].position_current);
            balance_check_2(player[0].bankbalance,token);
            buy_share(player[0].bankbalance , player[0].properties ,player[0].position_current );
            balance_check_2(player[0].bankbalance,token);
            pay_rent(player[0].bankbalance,player[1].bankbalance,player[1].properties,player[0].position_current);
            balance_check_2(player[0].bankbalance,token);
            buy_property(player[0].bankbalance, player[0].properties, player[1].properties ,player[0].position_current,buycheck,fcallcheck);
            balance_check_2(player[0].bankbalance,token);
            auction(data2,player,1,2,buycheck,fcallcheck);//auction is kept after buy as the fcallcheck and buycheck values depend on buyfunction
            sell(data2,player,1,2);
            drawrecnew(z,player,1,2);
            drawrecnew(z1,player,2,2);
            show_info(player[0]);
            chance_exit(token,player[0].bankbalance);
        }
        else
        {
           //chance of player 2
            cout<<"\n *****Chance of Player 2 *****\n"<<endl;
            token_move(c2,player[1].position_current,sum_dice(),player[1].bankbalance);
            Chance_Card(player[1].position_current, player[1].bankbalance);
            balance_check_2(player[1].bankbalance,token);
            lottery(player[1].bankbalance,player[1].position_current);
            balance_check_2(player[1].bankbalance,token);
            Jail(player[1].bankbalance,player[1].position_current);
            balance_check_2(player[1].bankbalance,token);
            buy_share(player[1].bankbalance , player[1].properties ,player[1].position_current );
            balance_check_2(player[1].bankbalance,token);
            pay_rent(player[1].bankbalance,player[0].bankbalance,player[0].properties,player[1].position_current);
            balance_check_2(player[1].bankbalance,token);
            buy_property(player[1].bankbalance, player[1].properties, player[0].properties ,player[1].position_current,buycheck,fcallcheck);
            balance_check_2(player[1].bankbalance,token);
            auction(data2,player,2,2,buycheck,fcallcheck);
            sell(data2,player,2,2);
            drawrecnew(z,player,1,2);
            drawrecnew(z1,player,2,2);
            show_info(player[1]);
            chance_exit(token,player[1].bankbalance);
        }
        }


 wait(40);
        }

        else if (no_players ==4)
        {
                Circle c1(570,570,5);//Initialization of tokens
            Circle c2(570,570,5);
            c1.setFill(true);
            c1.setColor(COLOR("green"));
            c2.setFill(true);
            c2.setColor(COLOR("red"));
             Circle c3(570,570,5);
            Circle c4(570,570,5);
            c3.setFill(true);
            c3.setColor(COLOR("yellow"));
            c4.setFill(true);
            c4.setColor(COLOR("blue"));

            int token = 0;
            playerinfo player[4];
            int players_remaining = 4;

            while(true)
            {
                if(token % 4 ==0)
                {
                             //chance of player 1
                    cout<<"\n *****Chance of Player 1 ***** \n"<<endl;
                    token_move(c1,player[0].position_current,sum_dice(),player[0].bankbalance);
                    lottery(player[0].bankbalance,player[0].position_current);
                    buy_share(player[0].bankbalance , player[0].properties ,player[0].position_current );
                    buy_property_4(player[0].bankbalance, player[0].properties, player[1].properties, player[2].properties, player[3].properties ,player[0].position_current,buycheck,fcallcheck);
                    pay_rent_4(player[0].bankbalance,player[1].bankbalance,player[2].bankbalance,player[3].bankbalance,player[0].properties,player[1].properties,player[2].properties,player[3].properties,player[0].position_current);
                    Chance_Card(player[0].position_current, player[0].bankbalance);
                    Jail(player[0].bankbalance,player[0].position_current);
                    balance_check_4(player[0].bankbalance,token,players_remaining,player[0].properties);
                    auction(data2,player,1,4,buycheck,fcallcheck);
                    sell(data2,player,1,4);
                    drawrecnew(z,player,1,4);
                    drawrecnew(z1,player,2,4);
                    drawrecnew(z2,player,3,4);
                    drawrecnew(z3,player,4,4);
                    show_info(player[0]);
                    chance_exit_4(token,player[1].bankbalance,player[2].bankbalance);
                }
                else if(token % 4 ==1)
                {
                             //chance of player 2
                    cout<<"\n *****Chance of Player 2 ***** \n"<<endl;
                    token_move(c2,player[1].position_current,sum_dice(),player[1].bankbalance);
                    lottery(player[1].bankbalance,player[1].position_current);
                    buy_share(player[1].bankbalance , player[1].properties ,player[1].position_current );
                    buy_property_4(player[1].bankbalance, player[1].properties, player[2].properties, player[3].properties, player[0].properties ,player[1].position_current,buycheck,fcallcheck);
                    pay_rent_4(player[1].bankbalance,player[2].bankbalance,player[3].bankbalance,player[0].bankbalance,player[1].properties,player[2].properties,player[3].properties,player[0].properties,player[1].position_current);
                    Jail(player[1].bankbalance,player[1].position_current);
                    Chance_Card(player[1].position_current, player[1].bankbalance);
                    balance_check_4(player[1].bankbalance,token,players_remaining,player[1].properties);
                    auction(data2,player,2,4,buycheck,fcallcheck);
                    sell(data2,player,2,4);
                    drawrecnew(z,player,1,4);
                    drawrecnew(z1,player,2,4);
                    drawrecnew(z2,player,3,4);
                    drawrecnew(z3,player,4,4);
                    show_info(player[1]);
                    chance_exit_4(token,player[2].bankbalance,player[3].bankbalance);
                }

                else if(token % 4 ==2)
                {
                             //chance of player 3
                    cout<<"\n *****Chance of Player 3 ***** \n"<<endl;
                    token_move(c3,player[2].position_current,sum_dice(),player[2].bankbalance);
                    lottery(player[2].bankbalance,player[2].position_current);
                    buy_share(player[2].bankbalance , player[2].properties ,player[2].position_current );
                    buy_property_4(player[2].bankbalance, player[2].properties, player[3].properties, player[0].properties, player[1].properties ,player[2].position_current,buycheck,fcallcheck);
                    Chance_Card(player[2].position_current, player[2].bankbalance);
                    pay_rent_4(player[2].bankbalance,player[3].bankbalance,player[0].bankbalance,player[1].bankbalance,player[2].properties,player[3].properties,player[0].properties,player[1].properties,player[2].position_current);
                    Jail(player[2].bankbalance,player[2].position_current);
                    balance_check_4(player[2].bankbalance,token,players_remaining,player[2].properties);
                    auction(data2,player,3,4,buycheck,fcallcheck);
                    sell(data2,player,3,4);
                    drawrecnew(z,player,1,4);
                    drawrecnew(z1,player,2,4);
                    drawrecnew(z2,player,3,4);
                    drawrecnew(z3,player,4,4);
                    show_info(player[2]);
                    chance_exit_4(token,player[3].bankbalance,player[0].bankbalance);
                }

                else
                {
                             //chance of player 4
                    cout<<"\n *****Chance of Player 4 ***** \n"<<endl;
                    token_move(c4,player[3].position_current,sum_dice(),player[3].bankbalance);
                    lottery(player[3].bankbalance,player[3].position_current);
                    buy_share(player[3].bankbalance , player[3].properties ,player[3].position_current );
                    buy_property_4(player[3].bankbalance, player[3].properties, player[0].properties, player[1].properties, player[2].properties ,player[3].position_current,buycheck,fcallcheck);
                    pay_rent_4(player[3].bankbalance,player[0].bankbalance,player[1].bankbalance,player[2].bankbalance,player[3].properties,player[0].properties,player[1].properties,player[2].properties,player[3].position_current);
                    Jail(player[3].bankbalance,player[3].position_current);
                    Chance_Card(player[3].position_current, player[3].bankbalance);
                    balance_check_4(player[3].bankbalance,token,players_remaining,player[3].properties);
                    auction(data2,player,4,4,buycheck,fcallcheck);
                    sell(data2,player,4,4);
                    drawrecnew(z,player,1,4);
                    drawrecnew(z1,player,2,4);
                    drawrecnew(z2,player,3,4);
                    drawrecnew(z3,player,4,4);
                    show_info(player[3]);
                    chance_exit_4(token,player[0].bankbalance,player[1].bankbalance);
                }



            }


        }

}



