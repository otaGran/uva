//
// Created by beans on 2016/12/25.
//

#include<stdio.h>
#include<string.h>
#define MaxQueueSize 1000

typedef struct Time  /*定义时间结构体*/
{
    int hour;
    int minute;
}TimeType;

typedef struct Customer   /*定义客户结构体 包括客户编号，业务类型，存/取款金额，到达时间（时.分），离开时间（时.分），逗留时间*/
{
    int number;           /*客户编号*/
    int leixing;          /*业务类型：0代码存款，1代表取款*/
    long int money;       /*存/取款金额*/
    struct Time time1;    /*到达时间*/
    struct Time time2;    /*离开时间*/
    int time3;            /*逗留时间*/
}CustomerType;

typedef CustomerType DataType;   /*定义具体应用的数据类型为客户结构体类型*/

#include"SeqCQueue.h"

int main(void)
{
    struct Customer a[1000];     /*定义客户结构体数组*/
    int n=0;                     /*定义客户个数计数器n*/
    int totaltime=0;             /*定义所有客户总逗留时间*/
    float time0=0;               /*定义平均逗留时间*/
    SeqCQueue Queue1;            /*定义第一窗口队列*/
    SeqCQueue Queue2;            /*定义第二窗口队列*/
    struct Customer c;           /*定义出队列或去对头元素的存储空间*/
    int t=1;                     /*定义控制循环变量*/
    struct Time begintime;       /*定义银行开门时间*/
    struct Time finishtime;      /*定义银行关门时间*/
    long int Money;              /*定义银行现有存款金额*/
    int temp=1;                  /*定义当前客户业务是否成功办理业务变量 成功为1，其他为0*/

    printf("****************************************************************\n");
    printf("****************************************************************\n");
    printf("****                欢迎进入银行业务模拟系统                ****\n");
    printf("****************************************************************\n");
    printf("****************************************************************\n\n");
    printf("默认成功办理存取款业务的时间均为3分钟\n");
    printf("请输入银行开门时间（时 分），关门时间（时 分），现有存款金额（元）:\n");

    if(scanf("%d %d %d %d %d",&begintime.hour,&begintime.minute,&finishtime.hour,&finishtime.minute,&Money)!=5){
        printf("这里写错误讯息")
        return ;
    }

    QueueInitiate(&Queue1);
    QueueInitiate(&Queue2);
    while(t)
    {
        printf("请输入客户编号，业务类型（0为存款，1为取款），存/取款金额，到达时间：\n");
        scanf("%d",&a[n].number);
        scanf("%d",&a[n].leixing);
        scanf("%d",&a[n].money);
        scanf("%d",&a[n].time1.hour);
        scanf("%d",&a[n].time1.minute);
        a[n].time3=0;
        QueueAppend(&Queue1,a[n]);
        if((a[n].time1.hour*60+a[n].time1.minute<begintime.hour*60+begintime.minute)||(a[n].time1.hour*60+a[n].time1.minute>finishtime.hour*60+finishtime.minute))    /*判断客户到达时间是否正确*/
        {
            printf("错误!非营业时间\n");
            t=0;
            break;
        }
        else
        {
            if(n==0)                   /*第一个客户*/
            {
                if(a[n].time1.hour*60+a[n].time1.minute+3>finishtime.hour*60+finishtime.minute)   /*没办理完业务银行已经下班*/
                {
                    a[n].time2.hour=finishtime.hour;
                    a[n].time2.minute=finishtime.minute;
                    a[n].time3=a[n].time2.hour*60+a[n].time2.minute-a[n].time1.hour*60-a[n].time1.minute;
                    totaltime=totaltime+a[n].time3;
                    QueueDelete(&Queue1,&c);
                    printf("银行下班时间到!\n");
                    printf("编号%d号客户办理业务失败!\n",a[n].number);
                    printf("逗留时间为：%d:%d--%d:%d  ",a[n].time1.hour,a[n].time1.minute,finishtime.hour,finishtime.minute);
                    printf("共%d分钟\n",a[n].time3);
                    printf("当前银行存款总额：%d\n",Money);
                    n++;
                }
                else                       /*在银行工作时间内办理业务*/
                {
                    if(a[n].leixing==0)    /*办理存款业务*/
                    {
                        Money=Money+a[n].money;
                        a[n].time2.hour=a[n].time1.hour+(a[n].time1.minute+3)/60;
                        a[n].time2.minute=(a[n].time1.minute+3)%60;
                        a[n].time3=a[n].time3+3;
                        totaltime=totaltime+a[n].time3;
                        QueueDelete(&Queue1,&c);
                        printf("编号%d号客户业务办理成功\n",a[n].number);
                        printf("逗留时间为：%d:%d--%d:%d  ",a[n].time1.hour,a[n].time1.minute,a[n].time2.hour,a[n].time2.minute);
                        printf("共%d分钟\n",a[n].time3);
                        printf("当前银行存款总额：%d\n",Money);
                        n++;
                    }
                    else
                    {
                        if(Money>=a[n].money)        /*成功办理取款业务*/
                        {
                            Money=Money-a[n].money;
                            a[n].time2.hour=a[n].time1.hour+(a[n].time1.minute+3)/60;
                            a[n].time2.minute=(a[n].time1.minute+3)%60;
                            a[n].time3=a[n].time3+3;
                            totaltime=totaltime+a[n].time3;
                            QueueDelete(&Queue1,&c);
                            printf("编号%d号客户业务办理成功\n",a[n].number);
                            printf("逗留时间为：%d:%d--%d:%d  ",a[n].time1.hour,a[n].time1.minute,a[n].time2.hour,a[n].time2.minute);
                            printf("共%d分钟\n",a[n].time3);
                            printf("当前银行存款总额：%d\n",Money);
                            n++;
                        }
                        else                         /*办理取款业务失败，排入窗口2等待*/
                        {
                            QueueDelete(&Queue1,&c);
                            printf("银行当前存款余额不足!\n");
                            printf("编号%d号客户排入窗口2等待\n",a[n].number);
                            QueueAppend(&Queue2,a[n]);
                            temp=0;                  /*没办理成功的用temp标记*/
                            n++;
                        }
                    }
                }
            }
            else              /*非第一位客户*/
            {
                if(temp==1&&a[n].time1.hour*60+a[n].time2.minute<a[n-1].time2.hour*60+a[n-1].time2.minute)     /*若来的时候前面客户在办理业务则需要等待*/
                    a[n].time3=a[n].time3+a[n-1].time2.hour*60+a[n-1].time2.minute-a[n].time1.hour*60-a[n].time1.minute;
                if(a[n].time1.hour*60+a[n].time1.minute+a[n].time3+3>finishtime.hour*60+finishtime.minute)                  /*没办理完业务银行已经下班*/
                {
                    a[n].time2.hour=finishtime.hour;
                    a[n].time2.minute=finishtime.minute;
                    a[n].time3=a[n].time2.hour*60+a[n].time2.minute-a[n].time1.hour*60-a[n].time1.minute;
                    totaltime=totaltime+a[n].time3;
                    QueueDelete(&Queue1,&c);
                    printf("银行下班时间到!\n");
                    printf("编号%d号客户办理业务失败!\n",a[n].number);
                    printf("逗留时间为：%d:%d--%d:%d  ",a[n].time1.hour,a[n].time1.minute,finishtime.hour,finishtime.minute);
                    printf("共%d分钟\n",a[n].time3);
                    printf("当前银行存款总额：%d\n",Money);
                    n++;
                }
                else                                 /*在银行工作时间内办理业务*/
                {
                    if(a[n].leixing==0)              /*办理存款业务*/
                    {
                        Money=Money+a[n].money;
                        a[n].time2.hour=a[n].time1.hour+(a[n].time1.minute+a[n].time3+3)/60;
                        a[n].time2.minute=(a[n].time1.minute+a[n].time3+3)%60;
                        a[n].time3=a[n].time3+3;
                        totaltime=totaltime+a[n].time3;
                        QueueDelete(&Queue1,&c);
                        printf("编号%d号客户业务办理成功\n",a[n].number);
                        printf("逗留时间为：%d:%d--%d:%d  ",a[n].time1.hour,a[n].time1.minute,a[n].time2.hour,a[n].time2.minute);
                        printf("共%d分钟\n",a[n].time3);
                        printf("当前银行存款总额：%d\n",Money);
                        n++;
                    }
                    else
                    {
                        if(Money>=a[n].money)        /*成功办理取款业务*/
                        {
                            Money=Money-a[n].money;
                            a[n].time2.hour=a[n].time1.hour+(a[n].time1.minute+3)/60;
                            a[n].time2.minute=(a[n].time1.minute+3)%60;
                            a[n].time3=a[n].time3+3;
                            totaltime=totaltime+a[n].time3;
                            QueueDelete(&Queue1,&c);
                            printf("编号%d号客户业务办理成功\n",a[n].number);
                            printf("逗留时间为：%d:%d--%d:%d  ",a[n].time1.hour,a[n].time1.minute,a[n].time2.hour,a[n].time2.minute);
                            printf("共%d分钟\n",a[n].time3);
                            printf("当前银行存款总额：%d\n",Money);
                            n++;
                        }
                        else                         /*办理取款业务失败，排入窗口2等待*/
                        {
                            QueueDelete(&Queue1,&c);
                            printf("银行当前存款余额不足!\n");
                            printf("编号%d号客户排入窗口2等待\n",a[n].number);
                            QueueAppend(&Queue2,a[n]);
                            temp=0;
                            n++;
                        }
                    }
                }
            }


            if((a[n-1].leixing==0)&&QueueNotEmpty(Queue2)==1)
            {
                int j;                              /*控制队列2次数，使得不至于无限循环*/

                for(j=0;j<QueueLength(Queue2)&&QueueNotEmpty(Queue2)!=0;j++)
                {
                    QueueGet(Queue2,&c);
                    if(a[n-1].time2.hour*60+a[n-1].time2.minute+3>finishtime.hour*60+finishtime.minute)       /*判断银行是否下班*/
                    {
                        c.time2.hour=finishtime.hour;
                        c.time2.minute=finishtime.minute;
                        c.time3=c.time2.hour*60+c.time2.minute-c.time1.hour*60-c.time1.minute;
                        a[n-1].time2.hour=c.time2.hour;
                        a[n-1].time2.minute=c.time2.minute;
                        totaltime=totaltime+c.time3;
                        j--;
                        printf("银行下班时间到!\n");
                        printf("编号%d号客户办理业务失败!\n",c.number);
                        printf("逗留时间为：%d:%d--%d:%d  ",c.time1.hour,c.time1.minute,finishtime.hour,finishtime.minute);
                        printf("共%d分钟\n",c.time3);
                        printf("当前银行存款总额：%d\n",Money);
                        QueueDelete(&Queue2,&c);
                    }
                    else
                    {
                        if(c.money<=Money)
                        {
                            c.time2.hour=a[n-1].time2.hour+(a[n-1].time2.minute+3)/60;
                            c.time2.minute=(a[n-1].time2.minute+3)%60;
                            a[n-1].time2.hour=c.time2.hour;
                            a[n-1].time2.minute=c.time2.minute;
                            c.time3=c.time2.hour*60+c.time2.minute-c.time1.hour*60-c.time1.minute;
                            totaltime=totaltime+c.time3;
                            Money=Money-c.money;
                            printf("编号%d号客户办理业务成功\n",c.number);
                            printf("逗留时间为：%d:%d--%d:%d  ",c.time1.hour,c.time1.minute,c.time2.hour,c.time2.minute);
                            printf("共%d分钟\n",c.time3);
                            printf("当前银行存款总额：%d\n",Money);
                            QueueDelete(&Queue2,&c);
                            j--;
                            temp=1;
                        }
                        else
                        {
                            QueueDelete(&Queue2,&c);
                            QueueAppend(&Queue2,c);
                        }
                        //if(QueueNotEmpty(Queue2)==0)
                        //	break;
                    }
                }
            }
        }
        printf("继续工作请按1，结束请按0\n");
        scanf("%d",&t);
    }
    if(n!=0)
        time0=(float)totaltime/n;
    printf("银行共接待客户%d人\n",n);
    printf("所有客户总逗留时间为:%d\n",totaltime);
    printf("平均逗留时间为:%.1f\n",time0);
    printf("银行当前余额为:%d\n",Money);

}
//printf("%d\n",begintime.hour);
//printf("%d\n",begintime.minute);
//printf("%d\n",finishtime.hour);
//printf("%d\n",finishtime.minute);
//printf("%ld\n",Mone