#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
//IO��
#include <stdio.h>
int main()
{
	int a = 0;
	char c;
	int ret = scanf("%d %c", &a, &c);//2,scanf�ķ���ֵ�Ƕ����˼�����
	int reault=printf("hello%d", a);//ֻ�����hello,���ķ���ֵ��������ַ�����
	return 0;
}
#endif
#if 0
int main()
{
	//cout << hex << 10 << endl;//hex��ʾ������������ְ���16���Ƶķ�ʽ�������
	int a, b;
	cin >> a;
	fflush(stdin);//ˢ��
	cin >> b;
	return 0;
}
#endif
#include<fstream>
// ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // �˿�
};
struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")//���캯��
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		// ����ע��ʹ�ö����Ʒ�ʽ��д,д��ȥ
		ofstream ofs(_configfile, ifstream::out | ifstream::binary);//�������������
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		// ����ע��ʹ�ö����Ʒ�ʽ�򿪶�
		ifstream ifs(_configfile, ifstream::in | ifstream::binary);//�����������ļ�
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}
	void WriteText(const ServerInfo& info)
	{
		// ����ᷢ��IO��д���α�C�������׾ͼ򵥶��ˣ�
		// C ���Ե��Ȱ�����itoa��д
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}
	void ReadText(ServerInfo& info)
	{
		// ����ᷢ��IO�������α�C�������׾ͼ򵥶��ˣ�
		// C ���Ե��ȶ��ַ�������atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile; // �����ļ�
};
int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// �����ƶ�д
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// �ı���д
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}
