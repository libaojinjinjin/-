#include<iostream> 
#include<string>
#include<iomanip>
#include<Eigen/Dense>
#include<fstream>
#include<stdio.h>

using namespace std;
using namespace Eigen;

struct point//�����ر����ṹ�� 
{
	string ID;//���� 
	double H;//�߳� 
	int flag;//��ʶ�Ƿ�õ��߳� 
};

struct miaogaoju//��׼�漰������������ṹ�� Ƕ�� 
{
	struct point back;//���ӵ㼰��� 
	struct point front;//ǰ�ӵ㼰��� 
	double gaocha;//�۲�߲� 
	double juli;//�۲���� 
};

class lei
{
public:
	struct point yizhidian[20];//��֪��ṹ������ 
	int yizhidiancount = 0;
	struct point weizhidian[20];//δ֪��ṹ������ 
	int weizhidiancount = 0;
	struct miaogaoju gaocha[20];//�߲�ṹ������ 
	int gaochacount = 0;
	int duoyu=0;//����۲���
	 
	//�ļ���ȡ
	void duqu()
	{
		int a;
		cout<<"�Ƿ���׼���ö�ȡ�ļ����ǵĻ�����1������س�����ʼ��"<<endl;
		cin>> a;
		fstream f("duqu.txt");//fscanf��ȡ�����ַ�char�� ��ƥ��string��p1�޷���ȡ 
		string line;
		getline(f,line);
		duoyu=atoi( line.c_str() );
		cout<<duoyu<<endl;
		getline(f,line);
		yizhidiancount=atoi( line.c_str() );
		cout<<yizhidiancount<<endl;
		//��ȡ��֪�� 
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
		//��ȡδ֪�� 
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
		//��ȡ�߲�
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
/*	����̨����۲������� 
	//��֪������¼��  
	void yizhi()
	{
		cout << "���������۲�����";
		cin >>duoyu; 
		cout << "��������֪������";//   ��֪���ʶ1��δ֪���ʶ0��δ֪��߳�0 
		cin >> yizhidiancount;
		for (int i = 0; i < yizhidiancount; i++)
		{
			printf("�����%d�����ݵ�š��̡߳���ʶ\n", i + 1);
			cin >> yizhidian[i].ID;
			cin >> yizhidian[i].H;
			cin >> yizhidian[i].flag;
		}
	}
	// δ֪������¼�� 
	void weizhi()
	{
		cout << "������δ֪������";//   ��֪���ʶ1��δ֪��߳�0�ұ�ʾ0 
		cin >> weizhidiancount;
		for (int i = 0; i < weizhidiancount; i++)
		{
			printf("�����%d�����ݵ�š��̡߳���ʶ\n", i + 1);
			cin >> weizhidian[i].ID;
			cin >> weizhidian[i].H;
			cin >> weizhidian[i].flag;
		}
	}
	// �۲�����¼�� 
	void shujuluru()
	{
		cout << "������۲����ݸ�����";
		cin >> gaochacount;
		for (int i = 0; i < gaochacount; i++)
		{
			printf("�����%d�����ݺ���ID�����Ӹ̡߳����ӱ�ʶ��ǰ��ID��ǰ�Ӹ̡߳�ǰ�ӱ�ʶ������߲����\n", i + 1);//Ƕ�׽ṹ�� ����¼���鷳 
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
	//ID���Һ��������ض�Ӧ��ָ�� 
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

	//����Ƹ̣߳��ص��ѵ㣩                                
	void  jinsizuobiao()
	{
		tiaozhuan0://goto��ת�� 
		for (int i = 0; i < weizhidiancount; i++)
		{
			if (weizhidian[i].flag != 1)
			{
				for (int j = 0; j < gaochacount; j++)
				{
					if ((gaocha[j].front.ID == weizhidian[i].ID) && gaocha[j].back.flag == 1)
					{
						weizhidian[i].H = gaocha[j].back.H + gaocha[j].gaocha;/// �������ǰ��δ֪������֪��ǰ��δ֪����Ƹ߳� 
						gaocha[j].front.H=weizhidian[i].H; 
						gaocha[j].front.flag=1;
						weizhidian[i].flag = 1;
						
						for(int k=0;k<gaochacount;k++)                         //���δ֪���Ϊ�߲����������иõ㸳ֵ 
						{
							if(weizhidian[i].ID==gaocha[j].front.ID)
								gaocha[j].front.H=weizhidian[i].H;
							if(weizhidian[i].ID==gaocha[j].back.ID)
								gaocha[j].back.H=weizhidian[i].H;
						}
						
						break;//����ѭ�� 
					}
				}

				if (weizhidian[i].flag != 1)
				{
					for (int j = 0; j < gaochacount; j++)
					{
						if ((gaocha[j].back.ID == weizhidian[i].ID) && gaocha[j].front.flag == 1)//������к���δ֪ǰ����֪��δ֪����ӵ�߳� 
						{
							weizhidian[i].H = gaocha[j].front.H - gaocha[j].gaocha;
							gaocha[j].back.H=weizhidian[i].H; 
							gaocha[j].back.flag=1;
							weizhidian[i].flag = 1;
							
						for(int k=0;k<gaochacount;k++)                         //���δ֪���Ϊ�߲����������иõ㸳ֵ 
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
	    for(int l=0;l<weizhidiancount;l++) //�����Ƿ�����δ֪�㶼�Ѽ������ 
			{
				if (weizhidian[l].flag == 0) 
				{
					goto tiaozhuan0;//δ�����������ת��ͷ�ٴ�����  
				}
				 
					
			}
	}
	//����P�� 
	MatrixXd PP()
	{
		MatrixXd p(gaochacount, gaochacount);
		double value;
						
		for(int i=0;i<gaochacount;i++)//ȫ��ʼ��Ϊ0 
		{
			for(int j=0;j<gaochacount;j++)
			{
				p(i, j)=0;
			}
		}	
						
		for (int i = 0; i < gaochacount; i++)
		{
			value = (1.0 / gaocha[i].juli);//����Ȩ 
			p(i, i) = value;
		}		
		return p;
	}
	//����B�� 
	MatrixXd BB()
	{
		MatrixXd B(gaochacount, weizhidiancount);
		
		for (int i = 0; i < gaochacount; i++)
		{
			struct point* tmpBack = NULL;
			struct point* tmpFront = NULL;
			tmpBack = searchpoint(gaocha[i].back.ID);
			tmpFront = searchpoint(gaocha[i].front.ID);//ֱ���ø߲�����Ӧ��Ҳ���� 

			for (int j = 0; j < weizhidiancount; j++)
			{
				if (tmpBack->ID == weizhidian[j].ID)//δ֪����������ж� 
				{
					B(i, j) = -1; 
				}
				else if (tmpFront->ID == weizhidian[j].ID)//δ֪�����ǰ���ж�
				{
					B(i, j) = 1;
				}
				else
				{
					B(i, j) = 0;//�����ֱȶԽ�� 
				}
			}
		}
		return B;
	}
	//����l��
	MatrixXd LL()
	{
		MatrixXd L(gaochacount, 1);
		for (int i = 0; i < gaochacount; i++)
		{
			L(i, 0) = (gaocha[i].gaocha - (searchpoint(gaocha[i].front.ID)->H - searchpoint(gaocha[i].back.ID)->H));//search�����Ǳ���	     
		}
		return L*1000;
	}

};

int main()
{
	lei a;
	a.duqu();
	
//  a.yizhi();//¼�� 
//  a.weizhi();// ¼�� 
//  a.shujuluru();//¼��
    a.jinsizuobiao();
    cout<<"δ֪����ƣ�"<<endl; 
    cout<<a.weizhidian[0].H<<endl; //����̨��� 
    //����N_bb 
    MatrixXd N_bb;
	N_bb = a.BB().transpose()*a.PP()*a.BB();

	//����W 
	MatrixXd W;
	W = a.BB().transpose()*a.PP()*a.LL();

	//����x 
	MatrixXd x;
	x = N_bb.inverse()*W;

	//����v 
	MatrixXd v;
	MatrixXd h(a.gaochacount, 1);
	v = a.BB() * x - a.LL();
	for(int i=0;i<a.gaochacount;i++)
	{
		h(i, 0)=a.gaocha[i].gaocha;
	}

	//���������߳� 
	MatrixXd X_0(a.weizhidiancount,1);
	cout<<"������̣߳�"<<endl;
	for(int i=0;i<a.weizhidiancount;i++)
	{
		double d;
		cout<<a.weizhidian[i].ID<<endl; 
		X_0(i,0)=a.weizhidian[i].H;
		cout<<X_0(i,0)+x(i,0)/1000<<endl;//����̨���
	}
		
	//���㾫�� 
	MatrixXd b;
	b =v.transpose()*a.PP()*v; 

	double o;
	o = b(0,0)/a.duoyu;
	cout<<"��λȨ����"<<sqrt(o)<<endl; //����̨��� 
	
	MatrixXd c;
	c=o*a.PP().inverse();
	cout << fixed <<setprecision(3)<<c<<endl;//����̨��� 
	
	ofstream outfile;
	outfile.open("shuchu.txt");
	//������ļ�
	outfile<<"ƽ�����ļ���"<<endl;
	outfile<<endl;
	outfile<<"��ؾ���" <<endl;
	outfile<<"B��"<<endl;
	outfile<<a.BB()<<endl;
	outfile<<"P:"<<endl;
	outfile<<a.PP()<<endl;
	outfile<<"L:"<<endl;
	outfile<<fixed <<setprecision(0)<<a.LL()<<endl;
	outfile<<fixed <<setprecision(0)<<"W:"<<endl;
	outfile<<W<<endl;
	outfile<<endl;
	
	outfile<<"δ֪����Ƹ߳�:"<<endl;
	for(int i=0;i<a.weizhidiancount;i++)
	{
		outfile<<fixed <<setprecision(3)<<a.weizhidian[i].ID<<":"<<a.weizhidian[i].H<<"��m��"<<endl;
	}
	outfile<<"�߲����ֵ:"<<endl;
	outfile<<fixed <<setprecision(0)<<v<<"(mm)"<<endl;
	outfile<<"�߲�ƽ��ֵ:"<<endl;
	outfile<<fixed <<setprecision(3)<<h+v/1000<<"��m��"<<endl; 
	outfile<<"δ֪��̸߳���ֵ:"<<endl;
	outfile<<fixed <<setprecision(0)<<x<<"(mm)"<<endl;
	outfile<<"δ֪��߳�ƽ��ֵ:"<<endl;
	for(int i=0;i<a.weizhidiancount;i++)
	{
		double d;
		X_0(i,0)=a.weizhidian[i].H;
		outfile<<fixed <<setprecision(3)<<a.weizhidian[i].ID<<":"<<X_0(i,0)+x(i,0)/1000<<"��m��"<<endl; 
	}
		
	outfile<<"�̴߳���ֵ����:"<<endl;
	MatrixXd e(a.weizhidiancount, a.weizhidiancount);
	e=o*N_bb.inverse();
	for(int k=0;k<a.weizhidiancount;k++ )
	{
		outfile<<fixed <<setprecision(2) <<a.weizhidian[k].ID<<":"<<sqrt(e(k, k))<<"��mm��"<<endl;	
	}
	
	outfile<<"�߲�ƽ��ֵ����:"<<endl;
	for(int k=0;k<a.gaochacount;k++ )
	{
		outfile<<fixed <<setprecision(2) <<"h"<<k+1<<":"<<sqrt(c(k, k))<<"��mm��"<<endl;	
	}

	outfile.close(); 
}



