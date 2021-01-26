#include<iostream> 
#include<string>
#include<iomanip>
#include<Eigen/Dense>
#include<fstream>
#include<stdio.h>

using namespace std;
using namespace Eigen;

struct point//点的相关变量结构体 
{
	string ID;//点名 
	double H;//高程 
	int flag;//标识是否得到高程 
};

struct miaogaoju//瞄准涉及到相关联变量结构体 嵌套 
{
	struct point back;//后视点及相关 
	struct point front;//前视点及相关 
	double gaocha;//观测高差 
	double juli;//观测距离 
};

class lei
{
public:
	struct point yizhidian[20];//已知点结构体数组 
	int yizhidiancount = 0;
	struct point weizhidian[20];//未知点结构体数组 
	int weizhidiancount = 0;
	struct miaogaoju gaocha[20];//高差结构体数组 
	int gaochacount = 0;
	int duoyu=0;//多余观测量
	 
	//文件读取
	void duqu()
	{
		int a;
		cout<<"是否已准备好读取文件？是的话输入1，点击回车键开始："<<endl;
		cin>> a;
		fstream f("duqu.txt");//fscanf读取单个字符char型 不匹配string且p1无法读取 
		string line;
		getline(f,line);
		duoyu=atoi( line.c_str() );
		cout<<duoyu<<endl;
		getline(f,line);
		yizhidiancount=atoi( line.c_str() );
		cout<<yizhidiancount<<endl;
		//读取已知点 
		for (int i = 0; i < yizhidiancount; i++)
		{
			getline(f,line);		
			yizhidian[i].ID=line;
			cout<<yizhidian[i].ID<<endl;
			getline(f,line);
			yizhidian[i].H=atof(line.c_str());
			cout<<yizhidian[i].H<<endl;
			getline(f,line);
			yizhidian[i].flag=atoi(line.c_str());
			cout<<yizhidian[i].flag<<endl;
		}
		//读取未知点 
		getline(f,line);
		weizhidiancount=atoi( line.c_str() );
		for (int i = 0; i < weizhidiancount; i++)
		{
			getline(f,line);		
			weizhidian[i].ID=line;
			cout<<weizhidian[i].ID<<endl;
			getline(f,line);
			weizhidian[i].H=atof(line.c_str());
			cout<<weizhidian[i].H<<endl;
			getline(f,line);
			weizhidian[i].flag=atoi(line.c_str());
			cout<<weizhidian[i].flag<<endl;
		}
		//读取高差
		getline(f,line);
		gaochacount=atoi( line.c_str() );
		cout<<gaochacount<<endl;
		for (int i = 0; i < gaochacount; i++)
		{
			getline(f,line);		
			gaocha[i].back.ID=line;
			cout<<gaocha[i].back.ID<<endl;
			getline(f,line);
			gaocha[i].back.H=atof(line.c_str());
			cout<<gaocha[i].back.H<<endl;
			getline(f,line);
			gaocha[i].back.flag=atoi(line.c_str());
			cout<<gaocha[i].back.flag<<endl;
			
			getline(f,line);		
			gaocha[i].front.ID=line;
			cout<<gaocha[i].front.ID<<endl;
			getline(f,line);
			gaocha[i].front.H=atof(line.c_str());
			cout<<gaocha[i].front.H<<endl;
			getline(f,line);
			gaocha[i].front.flag=atoi(line.c_str());
			cout<<gaocha[i].front.flag<<endl;
			
			getline(f,line);
			gaocha[i].gaocha=atof(line.c_str());
			cout<<gaocha[i].gaocha<<endl;
			getline(f,line);
			gaocha[i].juli=atof(line.c_str());
			cout<<gaocha[i].juli<<endl;
		}

	}
/*	控制台输入观测量函数 
	//已知点数据录入  
	void yizhi()
	{
		cout << "请输入多余观测数：";
		cin >>duoyu; 
		cout << "请输入已知点数：";//   已知点标识1，未知点标识0，未知点高程0 
		cin >> yizhidiancount;
		for (int i = 0; i < yizhidiancount; i++)
		{
			printf("输入第%d个数据点号、高程、标识\n", i + 1);
			cin >> yizhidian[i].ID;
			cin >> yizhidian[i].H;
			cin >> yizhidian[i].flag;
		}
	}
	// 未知点数据录入 
	void weizhi()
	{
		cout << "请输入未知点数：";//   已知点标识1，未知点高程0且表示0 
		cin >> weizhidiancount;
		for (int i = 0; i < weizhidiancount; i++)
		{
			printf("输入第%d个数据点号、高程、标识\n", i + 1);
			cin >> weizhidian[i].ID;
			cin >> weizhidian[i].H;
			cin >> weizhidian[i].flag;
		}
	}
	// 观测数据录入 
	void shujuluru()
	{
		cout << "请输入观测数据个数：";
		cin >> gaochacount;
		for (int i = 0; i < gaochacount; i++)
		{
			printf("输入第%d个数据后视ID、后视高程、后视标识、前视ID、前视高程、前视标识、两点高差、距离\n", i + 1);//嵌套结构体 数据录入麻烦 
			cin >> gaocha[i].back.ID;
			cin >> gaocha[i].back.H;
			cin >> gaocha[i].back.flag;
			cin >> gaocha[i].front.ID;
			cin >> gaocha[i].front.H;
			cin >> gaocha[i].front.flag;
			cin >> gaocha[i].gaocha;
			cin >> gaocha[i].juli;
		}
	}
*/ 
	//ID查找函数，返回对应点指针 
	struct point* searchknow(string ID)
	{
		for (int i = 0; i < yizhidiancount; i++)
		{
			if (yizhidian[i].ID == ID)
			{
				return &yizhidian[i];
			}
		}
		return NULL;
	}

	struct point* searchunknow(string ID)
	{
		for (int i = 0; i < weizhidiancount; i++)
		{
			if (weizhidian[i].ID == ID)
			{
				return &weizhidian[i];
			}
		}
		return NULL;
	}
    
	struct point* searchpoint(string ID)
	{
		struct point* cp;
		cp = searchknow(ID);
		if (cp == NULL)
			cp = searchunknow(ID);
		return cp;
	}

	//求近似高程（重点难点）                                
	void  jinsizuobiao()
	{
		tiaozhuan0://goto跳转点 
		for (int i = 0; i < weizhidiancount; i++)
		{
			if (weizhidian[i].flag != 1)
			{
				for (int j = 0; j < gaochacount; j++)
				{
					if ((gaocha[j].front.ID == weizhidian[i].ID) && gaocha[j].back.flag == 1)
					{
						weizhidian[i].H = gaocha[j].back.H + gaocha[j].gaocha;/// 求解所有前视未知后视已知的前视未知点近似高程 
						gaocha[j].front.H=weizhidian[i].H; 
						gaocha[j].front.flag=1;
						weizhidian[i].flag = 1;
						
						for(int k=0;k<gaochacount;k++)                         //求出未知点后为高差数组中所有该点赋值 
						{
							if(weizhidian[i].ID==gaocha[j].front.ID)
								gaocha[j].front.H=weizhidian[i].H;
							if(weizhidian[i].ID==gaocha[j].back.ID)
								gaocha[j].back.H=weizhidian[i].H;
						}
						
						break;//跳出循环 
					}
				}

				if (weizhidian[i].flag != 1)
				{
					for (int j = 0; j < gaochacount; j++)
					{
						if ((gaocha[j].back.ID == weizhidian[i].ID) && gaocha[j].front.flag == 1)//求解所有后视未知前视已知的未知点后视点高程 
						{
							weizhidian[i].H = gaocha[j].front.H - gaocha[j].gaocha;
							gaocha[j].back.H=weizhidian[i].H; 
							gaocha[j].back.flag=1;
							weizhidian[i].flag = 1;
							
						for(int k=0;k<gaochacount;k++)                         //求出未知点后为高差数组中所有该点赋值 
						{
							if(weizhidian[i].ID==gaocha[j].front.ID)
								gaocha[j].front.H=weizhidian[i].H;
							if(weizhidian[i].ID==gaocha[j].back.ID)
								gaocha[j].back.H=weizhidian[i].H;
						}
							
							break;
						}
					}
				}
			}

		}
	    for(int l=0;l<weizhidiancount;l++) //检验是否所有未知点都已计算出来 
			{
				if (weizhidian[l].flag == 0) 
				{
					goto tiaozhuan0;//未计算出来的跳转到头再次推算  
				}
				 
					
			}
	}
	//计算P阵 
	MatrixXd PP()
	{
		MatrixXd p(gaochacount, gaochacount);
		double value;
						
		for(int i=0;i<gaochacount;i++)//全初始化为0 
		{
			for(int j=0;j<gaochacount;j++)
			{
				p(i, j)=0;
			}
		}	
						
		for (int i = 0; i < gaochacount; i++)
		{
			value = (1.0 / gaocha[i].juli);//计算权 
			p(i, i) = value;
		}		
		return p;
	}
	//计算B阵 
	MatrixXd BB()
	{
		MatrixXd B(gaochacount, weizhidiancount);
		
		for (int i = 0; i < gaochacount; i++)
		{
			struct point* tmpBack = NULL;
			struct point* tmpFront = NULL;
			tmpBack = searchpoint(gaocha[i].back.ID);
			tmpFront = searchpoint(gaocha[i].front.ID);//直接用高差数组应该也可以 

			for (int j = 0; j < weizhidiancount; j++)
			{
				if (tmpBack->ID == weizhidian[j].ID)//未知点遍历后视判断 
				{
					B(i, j) = -1; 
				}
				else if (tmpFront->ID == weizhidian[j].ID)//未知点遍历前视判断
				{
					B(i, j) = 1;
				}
				else
				{
					B(i, j) = 0;//第三种比对结果 
				}
			}
		}
		return B;
	}
	//建立l阵
	MatrixXd LL()
	{
		MatrixXd L(gaochacount, 1);
		for (int i = 0; i < gaochacount; i++)
		{
			L(i, 0) = (gaocha[i].gaocha - (searchpoint(gaocha[i].front.ID)->H - searchpoint(gaocha[i].back.ID)->H));//search函数非必需	     
		}
		return L*1000;
	}

};

int main()
{
	lei a;
	a.duqu();
	
//  a.yizhi();//录入 
//  a.weizhi();// 录入 
//  a.shujuluru();//录入
    a.jinsizuobiao();
    cout<<"未知点近似："<<endl; 
    cout<<a.weizhidian[0].H<<endl; //控制台输出 
    //计算N_bb 
    MatrixXd N_bb;
	N_bb = a.BB().transpose()*a.PP()*a.BB();

	//计算W 
	MatrixXd W;
	W = a.BB().transpose()*a.PP()*a.LL();

	//计算x 
	MatrixXd x;
	x = N_bb.inverse()*W;

	//计算v 
	MatrixXd v;
	MatrixXd h(a.gaochacount, 1);
	v = a.BB() * x - a.LL();
	for(int i=0;i<a.gaochacount;i++)
	{
		h(i, 0)=a.gaocha[i].gaocha;
	}

	//计算待定点高程 
	MatrixXd X_0(a.weizhidiancount,1);
	cout<<"待定点高程："<<endl;
	for(int i=0;i<a.weizhidiancount;i++)
	{
		double d;
		cout<<a.weizhidian[i].ID<<endl; 
		X_0(i,0)=a.weizhidian[i].H;
		cout<<X_0(i,0)+x(i,0)/1000<<endl;//控制台输出
	}
		
	//计算精度 
	MatrixXd b;
	b =v.transpose()*a.PP()*v; 

	double o;
	o = b(0,0)/a.duoyu;
	cout<<"单位权中误差："<<sqrt(o)<<endl; //控制台输出 
	
	MatrixXd c;
	c=o*a.PP().inverse();
	cout << fixed <<setprecision(3)<<c<<endl;//控制台输出 
	
	ofstream outfile;
	outfile.open("shuchu.txt");
	//输出到文件
	outfile<<"平差结果文件："<<endl;
	outfile<<endl;
	outfile<<"相关矩阵：" <<endl;
	outfile<<"B："<<endl;
	outfile<<a.BB()<<endl;
	outfile<<"P:"<<endl;
	outfile<<a.PP()<<endl;
	outfile<<"L:"<<endl;
	outfile<<fixed <<setprecision(0)<<a.LL()<<endl;
	outfile<<fixed <<setprecision(0)<<"W:"<<endl;
	outfile<<W<<endl;
	outfile<<endl;
	
	outfile<<"未知点近似高程:"<<endl;
	for(int i=0;i<a.weizhidiancount;i++)
	{
		outfile<<fixed <<setprecision(3)<<a.weizhidian[i].ID<<":"<<a.weizhidian[i].H<<"（m）"<<endl;
	}
	outfile<<"高差改正值:"<<endl;
	outfile<<fixed <<setprecision(0)<<v<<"(mm)"<<endl;
	outfile<<"高差平差值:"<<endl;
	outfile<<fixed <<setprecision(3)<<h+v/1000<<"（m）"<<endl; 
	outfile<<"未知点高程改正值:"<<endl;
	outfile<<fixed <<setprecision(0)<<x<<"(mm)"<<endl;
	outfile<<"未知点高程平差值:"<<endl;
	for(int i=0;i<a.weizhidiancount;i++)
	{
		double d;
		X_0(i,0)=a.weizhidian[i].H;
		outfile<<fixed <<setprecision(3)<<a.weizhidian[i].ID<<":"<<X_0(i,0)+x(i,0)/1000<<"（m）"<<endl; 
	}
		
	outfile<<"高程待定值精度:"<<endl;
	MatrixXd e(a.weizhidiancount, a.weizhidiancount);
	e=o*N_bb.inverse();
	for(int k=0;k<a.weizhidiancount;k++ )
	{
		outfile<<fixed <<setprecision(2) <<a.weizhidian[k].ID<<":"<<sqrt(e(k, k))<<"（mm）"<<endl;	
	}
	
	outfile<<"高差平差值精度:"<<endl;
	for(int k=0;k<a.gaochacount;k++ )
	{
		outfile<<fixed <<setprecision(2) <<"h"<<k+1<<":"<<sqrt(c(k, k))<<"（mm）"<<endl;	
	}

	outfile.close(); 
}



