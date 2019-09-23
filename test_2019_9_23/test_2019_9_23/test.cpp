#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#if 0
//IO流
#include <stdio.h>
int main()
{
	int a = 0;
	char c;
	int ret = scanf("%d %c", &a, &c);//2,scanf的返回值是读入了几个数
	int reault=printf("hello%d", a);//只输出了hello,它的返回值是输出的字符个数
	return 0;
}
#endif
#if 0
int main()
{
	//cout << hex << 10 << endl;//hex表示将它后面的数字按照16进制的方式进行输出
	int a, b;
	cin >> a;
	fflush(stdin);//刷新
	cin >> b;
	return 0;
}
#endif
#include<fstream>
// 使用文件IO流用文本及二进制方式演示读写配置文件
struct ServerInfo
{
	char _ip[32]; // ip
	int _port; // 端口
};
struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "bitserver.config")//构造函数
		:_configfile(configfile)
	{}
	void WriteBin(const ServerInfo& info)
	{
		// 这里注意使用二进制方式打开写,写出去
		ofstream ofs(_configfile, ifstream::out | ifstream::binary);//创建输出流对象
		ofs.write((const char*)&info, sizeof(ServerInfo));
		ofs.close();
	}
	void ReadBin(ServerInfo& info)
	{
		// 这里注意使用二进制方式打开读
		ifstream ifs(_configfile, ifstream::in | ifstream::binary);//创建输入流文件
		ifs.read((char*)&info, sizeof(ServerInfo));
		ifs.close();
	}
	void WriteText(const ServerInfo& info)
	{
		// 这里会发现IO流写整形比C语言那套就简单多了，
		// C 语言得先把整形itoa再写
		ofstream ofs(_configfile);
		ofs << info._ip << endl;
		ofs << info._port << endl;
		ofs.close();
	}
	void ReadText(ServerInfo& info)
	{
		// 这里会发现IO流读整形比C语言那套就简单多了，
		// C 语言得先读字符串，再atoi
		ifstream ifs(_configfile);
		ifs >> info._ip;
		ifs >> info._port;
		ifs.close();
	}
private:
	string _configfile; // 配置文件
};
int main()
{
	ConfigManager cfgMgr;
	ServerInfo wtinfo;
	ServerInfo rdinfo;
	strcpy(wtinfo._ip, "127.0.0.1");
	wtinfo._port = 80;
	// 二进制读写
	cfgMgr.WriteBin(wtinfo);
	cfgMgr.ReadBin(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	// 文本读写
	cfgMgr.WriteText(wtinfo);
	cfgMgr.ReadText(rdinfo);
	cout << rdinfo._ip << endl;
	cout << rdinfo._port << endl;
	return 0;
}
