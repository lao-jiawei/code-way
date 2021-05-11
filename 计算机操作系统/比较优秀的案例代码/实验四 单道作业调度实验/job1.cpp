#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 24  //设置作业数的最大值
typedef struct node
{
      char name[10];//作业名
       int arrivetime;//作业到达时间
       int requesttime;//作业要求服务时间
      int starttime; //开始时间
      int finishtime; //结束时间 
     float Ttime;//周转时间
      float p;//响应比
      float Wtime;//带权周转时间
  }JCB;  //作业控制块JCB
  
  static int N=5;  //系统默认作业数
  static int flag=0;  
  JCB job[MAX];   
  
  void FCFS();//先来先服务算法
  void SJF();//最短作业优先算法
  void HRRN();//最高响应比优先算法
  void getValue();//给每个作业内的相关参数赋值
  void input();//输入数据
  void print();//打印输入的数据列表
  void getp();//得到响应比
  int ReadFile();//读取文件中的数据
  void input1();//初始数据列表
  
  //读取文件数据
  int ReadFile()  //读取文件的函数
  {
      int m=0;
      int i=0;
      FILE *fp;     //定义文件指针
      fp=fopen("job.txt","r");  //调用fopen函数以只读的方式打开文件“3.txt”
      if(fp==NULL)  //指针为NULL代表打开文件失败
     {
         printf("File open error !\n");  //提示用户打开文件发生错误
          exit(0);  //这里应该是“exit(1);”才对，exit(0)表示正常运行程序导致退出程序；而exit(1)表示异常运行导致退出程序
      }
      printf("\n文件中的数据内容为：");    
      while(!feof(fp))  //feof函数是用来检测流上的文件结束符的函数，简单点理解就是检测文件是否结束，是则返回非0值，否则返回0值
      {               //在这个while循环中，当文件结束时便跳出循环
          
          fscanf(fp,"\n%s%d%d",&job[i].name,&job[i].arrivetime,&job[i].requesttime);  //fscanf()函数将数据读入//调用fscanf函数将数据从fp所指向的文件中拿出来，存放在job[i]的成员中
          printf("\n%3d%12d%15d",job[i].name,job[i].arrivetime,job[i].requesttime);  //输出到屏幕    //在屏幕上显示出来 
        i++;  //每设置好一个job[i]的成员信息就让i+1，把从文件拿出来的数据设置给下一个job[i]。
      };
      printf("\n");
      if(fclose(fp))     //关闭文件 //调用fclose函数关闭刚才拿数据的那个文件，防止数据流失。成功关闭会返回0值，否则返回非0值
      {
          printf("Can not close the file !\n"); //提示用户无法关闭文件 
          exit(0);  // 退出程序
      }
      m=i-1;  
     return m;
  
  }
  
  //伪随机数产生器
  int Pseudo_random_number()
  {
      int i,n;
      srand((unsigned)time(0));  //参数seed是rand()的种子，用来初始化rand()的起始值。
      //输入作业数
      n=rand()%23+5;
      for(i=0; i<=n; i++)
      {
          //作业到达时间
          job[i].arrivetime=rand()%29+1;
          //作业运行时间
          job[i].requesttime=rand()%7+1;
      }
      return n;
  
  }
  
  void input1()
  {
      int i;  //定义一个控制变量i
      printf("\n--------输入的数据为：\n");   
      printf("            作业名     到达时间   要求服务时间\n");    
      for(i=0; i<N; i++)  //设置一个for循环将每个作业的信息一一打印出来
      {
          printf("第%d个作业",i+1);  //这里的i既是控制变量，同时也充当数组下标的角色，而这里
          printf("  %4s% 13d %14d\n",job[i].name,job[i].arrivetime,job[i].requesttime);    //打印每个作业的三个信息，从左到右分别为作业名、到达时间、要求服务时间
      }
  }
  
  void input()//输入数据
  {
     int i, jobNum, choi;   //定义一个循环控制变量i用于后面的for循环，普通整型变量jobNum用于接收用户输入的作业数，普通整型变量用于接收用户输入的功能选项值，即要选择“自选”“伪随机”还是“读取文件”
	 char flag=0;   //这里怎么设置了一个字符型的flag？
     printf("_________________________________\n");   //从本句以下5句，都是在打印功能选择界面
      printf("1.自选作业个数并输入\n");
      printf("2.伪随机数产生器\n");
      printf("3.读取文件输入数据\n");
     printf("_________________________________\n");
     printf("****你的选择是：");   //提示用户输入对应的功能选项值
     scanf("%d", &choi);   //接收用户输入的功能选项值并保存在整型变量choi中。
     switch(choi)   //设置switch多分支语句来处理用户输入的功能选项值，不同的choi对应不同的case，发挥不同的功能
     {
     case 1:    //choi为1时，对应case 1，此时需要用户自己输入作业个数，并对每个作业情况进行说明描述
         {
             do{  //利用一个do-while循环来确保用户输入的作业个数在允许的范围以内，当不在允许的范围时，通过循环让用户重新输入
                 printf("****请输入作业个数(个数在2~24之间):");   //提示用户允许输入的范围
                 scanf("%d", &jobNum);   //输入作业数 
                 N=jobNum;   //这里的N是一个静态整型变量，同时也是一个全局变量，在程序的开头已经定义声明好了，N在本函数（即input函数）中，主要用于检验用户输入的作业个数是否在允许的范围以内
                 
  
             }
             while(N<2 || N>24);   //判断接收了jobNum的值的N是否超出允许范围，不超出则继续往下执行程序，超出则回到do循环开头
             break;  // 作业个数在允许的范围以内，跳出case 1，跳出整个switch语句
         }
     case 2:
         Pseudo_random_number();//产生随机数
         //input1();
         break;
     case 3:
         ReadFile();//读取文件         //input1();
         break;
     default:
         printf("\n !!!!!输入错误，请重新选择!!!!!\n");  //如果用户输入的choi的值不是1~3，则系统会提示输入错误，然后重新调用本函数，让用户重新选择 
         input();
         
     }

	 //当选择为“自选作业”时jobNum>0，执行该循环，其它选择时jobNum=0，不执行该循环
     for(i=0; i<jobNum; i++)  //设置for循环，逐一对每个作业的信息进行描述，当i的值等于或超过作业个数时，结束循环
     {
         printf("\n第%d个作业名:",i+1);  //作业的顺序是从第一个开始数的，而i是从0开始的（从0开始是因为i其实也被数组job用于做下标），所以要i+1
         scanf(" ");  //这句语句是什么意思？
         gets(job[i].name);    //输入作业名 
         printf("到达时间:");
         scanf(" %d",&job[i].arrivetime);    //输入作业达到时间 
         printf("要求服务时间:");
         scanf(" %d",&job[i].requesttime);    //输入作业要求服务时间 
         job[i].starttime=0;  //每个作业的开始时间都初始化为0，除了第一个，后面每个都会根据具体的运行情况而改变开始时间的值
         
    }
     input1(); //调用input1函数将刚才输入的每个作业的信息一一打印出来
 }
 
 void print()//打印输入的数据列表
 {
     int i;  //循环控制变量
    float TAvetime;  //定义一个单精度浮点型变量，用来接收平均周转时间的值
     float WAvetime;   //用来接收平均带权周转时间的值
     float TtimeSum=0;  //用来接收总的周转时间的值
     float WtimeSum=0;   //用来接收总的带权周转时间的值
     
     printf("            作业名      到达时间   要求服务时间  开始时间  完成时间  周转时间  带权周转时间\n");    
     for(i=0; i<N; i++)  //设置for循环将作业的信息一个一个地输出出来
     {
         TtimeSum+=job[i].Ttime;  //把作业的周转时间与TtimeSum相加再赋值给TtimeSum，实现每个作业周转时间的累加
       WtimeSum+=job[i].Wtime;    //把作业的带权周转时间与WtimeSum相加再赋值给WtimeSum
        printf("第%d个作业",i+1);   //提示用户这是第几个作业的信息
         printf("  %4s% 13d %14d %9d %10d %10.2f %10.2f\n",job[i].name,job[i].arrivetime,job[i].requesttime,job[i].starttime,job[i].finishtime,job[i].Ttime,job[i].Wtime);  
         //依次按顺序从左到右将作业的相关信息打印出来
     }
     TAvetime=TtimeSum/N;  //将总的周转时间除以作业个数，求出平均周转时间
     WAvetime=WtimeSum/N;  //将总的带权周转时间除以作业个数，求出平均带权周转时间
     printf("平均周转时间为：%.2f",TAvetime);  //打印平均周转时间
    printf("\n平均带权周转时间为：%.2f",WAvetime);   //打印平均带权周转时间
 }

 void choice()//选择调度算法
 {
     int mark;  //定义一个整型变量用来接收用户输入的选项值，即要选择用什么算法或退出或返回主菜单
     printf("\n\n--------------------------------------------- ");  //打印选择界面
     printf("\n        1.先来先服务(FCFS)调度算法;");
     printf("\n        2.最短作业优先(SJF)调度算法;");
     printf("\n        3.最高响应比优先(HRRF)调度算法; ");
     printf("\n        4.退出;       ");
     printf("\n        5.返回主菜单       ");
     printf("\n---------------------------------------------\n");
     printf("\n        请选择算法：       ");  //提示用户输入选项值
     scanf("%d", &mark);   //接收用户输入的选项值
     switch(mark)   //设置switch多分支语句实现多种功能的选择
    {
   case 1:
         printf("\n********************先来先服务(FCFS)调度算法结果*****************\n\n");
         FCFS();     //先来先服务算法
         choice();  //为了完成一次作业调度后再回到选择界面，这里需要再次调用choice函数，下面的case中以及default中都有相同的用法，下面不再赘述
         break;   //为了保证程序只执行case 1就结束，用break语句防止执行完case 1 后程序还继续往后执行，下面case中的break语句也同理，不再赘述
     case 2:
        printf("\n********************最短作业优先(SJF)调度算法结果*****************\n\n");
         SJF();     //最短作业优先算法
         choice();  
         break;
    case 3:
         printf("\n********************最高响应比优先(HRRF)调度算法结果*****************\n\n");
         HRRN();     //最高响应比优先算法
         choice();
         break;    
     case 4:
         return;  //返回主函数，结束程序的运行
     case 5:
         input();
         choice();
         break;
    default:
         printf("\n !!!!!!输入错误，请重新选择!!!!!!");  //提示用户输入错误
         choice();
     }
 }
 
 void getValue() //给每个作业内的相关参数赋值  //赋值的过程也就是在模拟作业运行的情况，前面的算法已经按到达的先后顺序排好，在这里直接按顺序一个接一个运行即可
 {
    int i;  //定义控制变量
     
     for(i=0; i<N; i++)   //设置循环，模拟作业一个接一个运行的过程
     {
         if(i==0 || job[i].arrivetime>job[i-1].finishtime)  //判断当前作业是否为第一个，是则i==0，执行if语句的内容，否则要看当前作业的到达时间是否比刚刚完成的作业的完成时间还要晚，是则执行if语句内容，否则不执行（只有当当前作业既不是第一个，而且它的到达时间又比刚刚完成的作业的完成时间早时，才不执行if语句的内容）
             job[i].starttime=job[i].arrivetime;  //把到达的时间赋值给开始时间即表示运行。因为如果你是第一个，那么你一到达就可以运行了；如果你不是第一个，而且你是在前一个作业完成了之后才来的，那也可以让你运行。注：到达时间已经按前后顺序排好，不用考虑“有多个作业都是在某个作业完成了之后才来的，到底要选哪一个”的问题
        else
             job[i].starttime=job[i-1].finishtime;  //如果既不是第一个，而且来的时候前一个作业还没有完成，那就要等前一个完成后才能紧接着上，所以前一个完成的时候，就是当前作业可以运行的时候。
         job[i].finishtime=job[i].requesttime+job[i].starttime;  //作业完成的时间等于作业开始运行的时间加上它要求服务的时间（即需要运行多久的时间）
         job[i].Ttime=(float)job[i].finishtime-(float)job[i].arrivetime;  //作业的周转时间等于作业的完成的时间减去作业到达的时间（即等待时间+要求服务的时间）
         job[i].Wtime=(float)job[i].Ttime/(float)job[i].requesttime;    //带权周转时间等于周转时间除以要求服务的时间
         
     }
 }
 
 void FCFS()//先来先服务算法
 {
     int i, j;  //定义两个循环控制变量i，j
     JCB mark;    //创建一个作业控制块，用于辅助两个作业控制块的交换操作，以防止两个控制块交换时其中一个控制块的信息被覆盖而产生错误
     for(i=0;i<N-1; i++)  //通过作业到达时间整体排序   //这个for循环是外循环，设置这个循环目的在于一个一个地确定好每个元素的位置，第一个元素确定好就确定第二个，以此类推，直到把所有元素的位置都确定好为止。
     {
         for(j=i+1; j<N; j++)  //这个for循环使内循环，设置这个循环目的在于遍历比较，确定每个元素的位置时需要把该元素与其后面的元素一一进行比较，所以需要遍历当前正在确定位置的那个元素它后面的所有元素。
         {
             if(job[j].arrivetime<job[i].arrivetime)//冒泡排序  //判断当前正在确定位置的元素（为了方便描述，后面的注释称为当前元素）与遍历到的那个元素（为便于描述，后面称为遍历元素），看看当前元素的到达时间值是否比遍历元素的到达时间大（即来的晚）。是则交换这两个控制块的位置，否则不交换。
             {
                 mark=job[j];   //先把当前元素（即作业控制块）的信息先暂时存放到作业控制块mark中，防止信息被覆盖后找不回原来的信息
               job[j]=job[i];   //把遍历元素的信息赋值给当前元素，将当前元素原有的信息覆盖，此时两个元素的信息就一样了，可以不严谨地理解为当前元素变成了遍历元素。
                 job[i]=mark;   //由于上一个语句的操作导致当前元素信息被覆盖，此时就要用到mark来提供当前元素原有的信息。将mark的值赋值给遍历元素，遍历元素的信息就和当前元素原来的信息一样，不严谨地讲，此时的遍历元素就变成了原来的当前元素，至此，便实现了两者的交换。
             }
         }
     }
    getValue();//给每个作业内的相关参数赋值
    print();  //打印出结果
}
 
 void SJF()//最短作业优先算法  //该算法的思路与先来先服务算法基本相同，只不过冒号排序时比较的不是到达时间，而是要求服务的时间，这里便不再赘述
 {
     int i, j;  //循环控制变量i与j
     JCB mark;    //作业控制块mark
     for(i=1;i<N-1; i++)  //通过作业所需运行时间整体排序 
     {
         for(j=i+1; j<N; j++)
         {
             if(job[j].requesttime<job[i].requesttime)//冒泡排序  //与先来先服务算法的不同之处，比较作业的requesttime即作业要求服务的时间
             {
                 mark=job[j];
                 job[j]=job[i];
                 job[i]=mark;    
             }
         }
     }
     getValue();  //给每个作业内的相关参数赋值
     print();  //打印出结果
     
 }
 
 void HRRN()//最高响应比优先算法
 {
     int i, j;  
     JCB mark;
     for(i=1;i<N-1; i++)  //通过到达时间整体排序  //这里的两个for循环还是冒号排序法，思路与先来先服务算法中用到的冒号排序法一致，不再赘述
     {                                            //这里的冒号排序同样也是按到达时间的前后进行排序的
         for(j=i+1; j<N; j++)
         {
			if(job[j].arrivetime<job[i].arrivetime)
             {
                 mark=job[j];
                 job[j]=job[i];
                 job[i]=mark;    
             }
         }
     }
     job[0].starttime=job[0].arrivetime;      //本语句以及以下三个语句，是在模拟第一个作业的运行情况，将开始时间、周转时间等设置好，方便后面打印出来  //最先进来，所以最先开始运行，到达时间即开始运行时间
     job[0].finishtime=job[0].requesttime+job[0].starttime;;
     job[0].Ttime=job[0].finishtime-job[0].arrivetime;
     job[0].Wtime=(float)job[0].Ttime/(float)job[0].requesttime;
     
     flag=0;
     getp();  // 得到响应比
     print();  //打印出来
 }
 
 void getp()//得到响应比
 {
     int i, j;
     JCB mark2;
     do{  //除了最先进来的那个作业外，其他的每个作业都要经过一番计算才能确定是第几个运行，并且每次只能确定一个，如只有当第二个确定是那个作业是哪个运行后，才能确定第三个是哪个作业运行。设置do-whilie就是为了实现一个一个地确定作业运行的顺序
         for(i=flag+1; i<N; i++)   //设置for循环是为了将未确定好运行顺序的作业job[i]的最高响应比一个一个地计算出来，以刚刚最新确定好运行顺序的作业job[flag]为标准去计算。
         {
             if(job[i].arrivetime>job[flag].finishtime)    //后面的与第一个对比  //一开始flag==0（因为是下标，所以是从0开始的，作业的运行顺序每确定好一个，flag的值就会加1），意味着刚刚最新确定好运行顺序的作业是第一个。
				                                            //未确定好运行顺序的作业job[i]每一个都当做是即将要运行的作业，紧接在最新确定好运行顺序的作业job[flag]后面，然后计算他们的最高响应比，直到计算完所有未确定运行顺序的作业的最高响应比为止                
                 job[i].starttime=job[i].arrivetime;     //如果job[i]在job[flag]完成了之后才来的，那job[i]一到达就可以运行。
             else
                 job[i].starttime=job[flag].finishtime;   //如果job[i]在job[flag]完成了之前就来了，那么job[flag]一完成，job[i]就可以开始运行了
           job[i].finishtime=job[i].requesttime+job[i].starttime;  //计算完成时间
             job[i].Ttime=job[i].finishtime-job[i].arrivetime;   //计算周转时间 
             job[i].Wtime=(float)job[i].Ttime/(float)job[i].requesttime;  //计算带权周转时间
         }
         for(i=flag+1;i<N-1; i++)  //后面的元素 根据响应比整体排序 得到高响应比的元素 
         {  //通过上面那个for循环后，未确定好运行顺序的作业的最高响应比都被计算出来了，但是乱序的，所以要通过冒号排序来将最高响应比进行排序，从而得到最高响应比最大的那一个
             for(j=i+1; j<N; j++)
             {
                 if(job[j].Wtime>job[i].Wtime)   //和前面的其他算法的冒号排序思路相同，只不过这里比较的是最高响应比。
                 {
                     mark2=job[j];
                     job[j]=job[i];
                     job[i]=mark2;                    }
             }
         }
         flag++;  //最高响应比最大的作业选出来后，就意味确定好运行顺序的作业又多加了一个，所以标志flag+1.
     }while(flag<N);  //flag的值标志着确定好运行顺序的作业的个数，而且它是从0开始的，当flag的值等于作业总个数N时，就意味着所有的作业的运行顺序都确定好了，那么便跳出do-while循环。
 }
 
 void main()
 {
     printf("\n*************************欢迎使用作业调度模拟程序*************************\n\n");   //打印开始界面
     input();     //输入    //调用input函数打印相关的功能选项，同时接收用户的输入情况
     //print();     //打印输出 
     choice();    //选择调度算法
 }

