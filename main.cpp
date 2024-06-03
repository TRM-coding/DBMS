#include<TableStream.hpp>
#include<table.hpp>
<<<<<<< HEAD
#include<commanddecoding.hpp>
#include <usermanage.hpp>
#include<ans.hpp>
using namespace std;
int main(){
    std::cout<<"username:";
    string username;
    cin>>username;
    cout<<endl;
    std::cout<<"password:";
    string password;
    cin>>password;
    cout<<endl;
    User user;
    Ans answer;
    if(UserManager::LoginByUsers(username,password,user,answer)){
        cout<<"Login success!"<<endl;
    }else{
        cout<<"Login failed!"<<endl;
        return 0;
    }
    // Ans ans;
    while(1){
        string s;
        getline(cin,s);
        CommandDecoding cd(s,user,answer);
        auto data=answer.getdata();
        for(auto x:data)
        {
            for(auto y:x){
                std::cout<<y<<" ";
            }
            std::cout<<std::endl;
        }
        cout<<endl;
    }

    // system("pause");
}

// select * from s join class on s.classno = class.classno
// select * from class sc
// insert into class ( classno , className , ClassMajor , scchool ) values ( Rj2206 , SW2205 , CS , NJU )
// insert into class ( classno , className , ClassMajor , school ) values ( Rj2206 , SW2205 , CS , NJU )
// insert into class ( classno , className , ClassMajor , school ) values ( Rj2207 , SW2205 , CS , NJU )
// insert into class ( className ) values ( SW2208 )
// insert into class ( classno , className , ClassMajor ) values ( Rj2208 , SW2208 , CS )
// insert into class ( classno , className , ClassMajor , school ) values ( neRj2208 , neSW2208 , CS , BJTU )
// insert into s ( sno , sname , sex , birthday , classno Totalcredit ) values ( 1 , 1 , 1 , 1 , 1 , 1 )
// insert into s ( sno , sname , sex , birthday , classno Totalcredit ) values ( 5 , 1 , 1 , 1 , Rj2206 , 1 )
// insert into s ( sno , sname , sex , birthday , classno Totalcredit ) values ( 6 , 1 , 1 , 1 , Rj2206 , 1 )
// insert into s ( sno , sname , sex , birthday , classno Totalcredit ) values ( 7 , 1 , 1 , 1 , Rj2206 , 1 )
// insert into s ( sno , sname , sex , birthday , classno Totalcredit ) values ( 8 , 1 , 1 , 1 , Rj2206 , 1 )

//delete from class where classno = Rj2206

// update class set newcolum = RJ801 where classno = Rj0801
// update class set className = SW2206 where classno = Rj0801
// update class set className = SF where classno = Rj0801
// update class set className = SW2209 where classno = Rj2208 and ClassMajor = CS and school = "BJTU"
// update class set className = newSW2209 ClassMajor = newCS where classno = Rj2208 and ClassMajor = CS and school = "BJTU"

// alter table class add column cno char unique not null
// alter table class add column testnew char(8) not null
// alter table class add column testnew char(8) not null
// alter table class add column testnew2 char(8) default 2 not null
// alter table class add column testnew3 char(8) not null default 2

// alter table s add constraint FK:classno foreign key classno references class classno
// alter table sc add column classno char(255) default 0000 not null foreign key ( classno ) references class ( classno )


// create user test2 identified by 123456


// select s.sno sname grade from s join sc on s.sno = sc.sno where grade >= 80 order by grade
// select s.sno sname grade from s join sc on s.sno = sc.sno
// select * from s join class on s.classno = class.classno

// insert into sc ( sno , cno , grade , year ) values ( 08300097 , 806 , 68 , 2004 )
// update sc set grade = 90 where sno = 08300077 and cno = 806
// alter table t1 add column test1 int
// drop table t1
// insert into sc ( sno , cno , grade , year ) values ( 22301131 , 801 , 90 , 2004 )
// update sc set grade = 100 where sno = 08300077 and cno = 806
// delete from s where sno = 08300077
// delete from sc where sno = 08300077 and cno = 806
// select sno , cno , grade from sc join s on sc.sno = s.sno where grade >= 80 order by grade
// select s.sno , cno , grade from sc join s on sc.sno = s.sno where grade >= 80 order by grade

// select * from sc where grade >= 80 and sno = 08300030 
// select * from sc where grade >= 80 or grade <= 60
// select * from sc where not grade >= 80 

// create user test2 identified by 123456

// grant all on t1 to root

// alter table t1 drop column a4

// alter table t1 add column test1 bigint


//default 解析不对
//级联删除，级联修改维护有问题
=======
using namespace std;
int main(){
    // TableStream::ROOT_DIR=DBMSROOTDIR;
    std::cout<<TableStream::ROOT_DIR<<std::endl;
    Table tb1=TableStream::LoadTable("table1.tb");
    for(auto x:tb1.getData()){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    // system("pause");
}
>>>>>>> refs/remotes/origin/main
