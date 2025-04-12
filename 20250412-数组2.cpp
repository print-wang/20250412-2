#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include <array>
#include <iomanip>

int main() {
	//本周内容： 静态数组与动态数组  数组长度  文件输入输出 练习题 
//	
//	4、静态数组与动态数组  
//	包括声明、使用、释放 
//	静态数组：在编译时确定大小、存储在栈上，生命周期与作用域绑定，出了作用域自动销毁释放；一般适用于数据量固定且较小的情况； 系统自动分配内存，也自动释放； 
//	动态数组：运行时通过new 分配内存，存储在堆上，生命周期由程序员决定，须手动释放； 适用于数据量未知或变化的情况；需要手动释放内存，若遗忘易导致内存泄漏； 
			 //可能导致的内存碎片问题 ；new 与 delete  ；new[] 与 delete[] 配对使用 ； 或用c 风格的 Malloc 声明，free()释放； 
			 //推荐使用标准库向量容器 vector ，封装了动态数组，使用更方便也更安全；
//	int arr[10];  //声明 静态数组 
//	int * arr= new int[10]; //声明 动态数组    delete [] arr; 释放内存空间 
	 // 静态数组  
//    int staticArr[3] = {10, 20, 30};
//    cout << "Static Array: ";
//    for (int i = 0; i < 3; i++) cout << staticArr[i] << " ";
//    cout << endl;
//    
//    staticArr[3]=0;  // error  危险行为  可能可以编译执行，但越界赋值 将可能产生未定义不可预知问题  属于非法无效 
//    cout<<staticArr[3]<<endl;
//    
//    int size = sizeof(staticArr)/sizeof(staticArr[0]);
//    
//    cout<<size<<endl;
//    
//    for (int i = 0; i < size; i++) cout << staticArr[i] << " ";
//    cout << endl;


	// 动态数组 
//    int size = 4;
//    int* dynamicArr = new int[size]{5, 10, 15, 20};
//    cout << "Dynamic Array: ";
//    for (int i = 0; i < size; i++) cout << dynamicArr[i] << " ";
//    cout<<endl;
//    
//    dynamicArr[4]=25; // error  越界，非法赋值无效   虽然是动态数组， 也需要先增加数组长度，再增加新元素   
//    cout << dynamicArr[4]<<endl;
//    
////    size++;
////    dynamicArr[4]=35; // ok  先增加数组长度，再增加新元素
////    cout << dynamicArr[4]<<endl;
//    
//    
//    for (int i = 0; i < size; i++) cout << dynamicArr[i] << " ";
//    cout<<endl;
//    
//    delete[] dynamicArr;


//	5、动态数组的进阶用法 推荐使用标准库 vector容器
//  vector向量 容器是一个能够存放任意类型的动态数组 ；
//  一维数组：vector <int> a  <=> int a[] ；二维数组： vector <int *> a <=> int a[][] 

//	vector <int> vec; // 定义整型空容器 vec;  等于声明了一个int型数组 vec[] 大小不定  可以动态的向里面添加删除元素 ； 
//	cout<<vec.size()<<endl;   //0  .size() 得到容器实际数据个数 
//
//	vector <int> vec={0,3}; // 定义整型容器vec 且赋值 
//	vec.push_back(1); //尾部插入 1 
//	vec.push_back(2); //尾部插入 2
//    vec.pop_back(); //弹出最后一个元素  2
//	cout<<vec.size()<<endl;  //3   容器vec随着插入数据不断增大 
//	for(int i=0;i<vec.size();i++) printf("%d ",vec[i]); cout<<endl;  //数组下标遍历容器方式1  //0 3 1
//	for(int i=0;i<vec.size();i++) printf("%d ",vec.at(i));cout<<endl;//数组下标遍历容器 方式2  注意 .at()  是括号 
//	for(vector<int>::iterator it=vec.begin();it!=vec.end();++it) printf("%d ",*it);cout<<endl;//用迭代器遍历容器 方式3
//	vec.resize(10);  //直接调整容器大小 
//	cout<<vec.size()<<endl; 
//	for(int i=0;i<vec.size();i++) printf("%d ",vec[i]); cout<<endl;  //0 3 1 0 0 0 0 0 0 0 

	//////////延伸出vector 容器的相关函数用法实例/////////////////////		
//	vector<int> myVector; // 创建一个存储整数的空 vector
//	vector<int> myVector(5); // 创建一个包含 5 个整数的 vector，每个值都为默认值（0）
//	vector<int> myVector(5, 10); // 创建一个包含 5 个整数的 vector，每个值都为 10
//	myVector.push_back(7); // 将整数 7 添加到 vector 的末尾
//	int x = myVector[0]; // 获取第一个元素
//	int y = myVector.at(1); // 获取第二个元素  注意at后面是括号  at 是成员函数 
//	int size = myVector.size(); // 获取 vector 中的元素数量
//	vector<int> vec2 = {1, 2, 3, 4}; // 初始化一个包含元素的 vector
//	vector<int>::iterator it;  //声明 一个迭代器 it;
//	for(it=vec2.begin();it!=vec2.end();it++) //使用迭代器遍历 vector 中的元素   
//		cout<<*it<<endl; //解引用输出 
//	myVector.erase(myVector.begin() + 2); // 删除第三个元素
//	myVector.clear(); // 清空 vector

	//参考 C++ vector 容器浅析   https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html   




	//静态数组和动态数组都需要注意越界问题 ； 
//静态数组在声明时边界就已经确定 【0，SIZE-1】，不可动态增加，更不能越界访问。 
//动态数组vector在没有通过push_back()等成员函数方法动态增加元素个数前，其有效索引范围也是有限的，也不能越界访问不存在的元素。 
//传统的数组下标（vec[]）访问数组元素方式：不会做越界检测； 
//而使用 vector中的成员函数 .at(i) 访问前会进行边界检查，若越界，则抛出 out_of_range异常。 
//如何避免越界问题访问发生？
//1、vector遍历时使用  成员函数 .at(i) ；
//2、for(auto it=p.rbegin();it != p.rend();it++) cout<<*it<<" ";
//3、for(int x: vec) cout<<x<<" "; 



//输入不确定个数整数，当输入-1结束输入，逆序输出？
	//方法 1 静态数组 

//	const int SIZE = 1000;
//	int a[SIZE];
//	int x,n=0;
//	cin>>x;
//	while(x != -1) {
//		a[n++] = x;  //填充数组 
//		cin>>x;	
//	}
//	
//	for(int i=n-1;i>=0;i--) cout<<a[i]<<" ";
//


//输入不确定个数整数，当输入-1结束输入，逆序输出？
//方法 2  new 动态数组  赋值之前不断的加大数组空间  
/*
思路：
1、确定当前数组大小
2、创建更大的新数组
3、复制元素
4、添加新元素
5、释放原数组内存
6、更新指针
7、更新长度
评价：这种方法每次添加元素都需要重新分配 内存和复制元素，效率不高；若需要频繁添加元素，建议使用vector 它会自动处理内存管理和大小调整
*/
//	int size=2;
//	int *p = new int [size];  // 当前数组大小
//	
//	int x,n=0;  
//	cin>>x;
//	while(x != -1) {
//		if(n>=size) {  //在填充数组之前，先评估空间够不够 
//			int newsize=size*2;
//			int *temp= new int[newsize];  	//创建更大的新数组
//			for(int i=0;i<size;i++){  //复制元素
//				temp[i]=p[i];
//			}
//			delete [] p;   //释放原数组内存
//			p=temp; //更新原指针
//			size=newsize; //更新数组长度 
//		}
//		p[n++] = x;   //填充数组  添加新元素
//		cin>>x;	
//	}
//	
//	if(n)  
//	for(int i=n-1;i>=0;i--) cout<<p[i]<<" ";
//	else cout<<"没有数据输入！";
//	
//	delete [] p;  //再释放



//输入不确定个数整数，当输入-1结束输入，逆序输出？
//方法 3 vector 动态数组 

//	vector<int> p;
//	
//	int x;
//	cin>>x;
//	while(x != -1) {
//		p.push_back(x);   //填充数组
//		cin>>x;	
//	}
//	
//	if(p.empty()) cout<<"没有数据输入！";
//	else {
//	for(int i=p.size()-1;i>=0;i--) cout<<p[i]<<" ";
//	cout<<endl;
//	for(int i=p.size()-1;i>=0;i--) cout<<p.at(i)<<" ";
//	cout<<endl;
//	for(auto it=p.rbegin();it != p.rend();it++) cout<<*it<<" ";
//	}

		//关于数组长度： 
//	char ch[]={'b','e','e'};   //字符数组  不是字符串 
//	char ch1[]={'b','e','e','s','\0'}; //c语言字符串  能用字符串函数操作 ,最后有字符串结束标识 '\0' 或 0 ,不是字符串一部分。 
// 
//	cout << "数组长度:" << end(ch1)-begin(ch1) << endl; //5
//	cout<<begin(ch1)+1<< endl;  //ees   
//	cout<<end(ch1)-2<< endl;  //s 
//	printf("ch_len = %d\n",sizeof(ch)/sizeof(ch[0]));  //3
//	printf("ch1_len = %d\n",sizeof(ch1)/sizeof(ch1[0])); //5  会统计结尾标识 '\0'
//	int a[100]={1,2,3,4,5,6,7,8};   //自定义函数得到数组内除0外的实际元素个数
//	for(int x: a) cout<<x<<" ";
//	
//	int elem_len(int *arr, int SIZE){ //自定义函数得到数组内除0外的实际元素个数 
//		int count=0;
//		for(int i=SIZE-1;i>=0;i--)
//			if(arr[i] != 0) count++;
//		return count;
//	}

	//关于比赛用文件输入输出？ 

	//求输入一些数据，输出（-1结束）所有大于平均值的数
//	int x, a[100],ii=0,s=0;
//	cin>>x;
//	
//	while(x!=-1) {	
//		a[ii]=x;
//		s+=x;
//		ii++;
//		cin>>x;	
//	}
//	
//	double aver=1.0*s/ii;
//	printf("aver(%.2f)=%d/%d\n",aver,s,ii);
//	for(int i=0;i<ii;i++){
//		if(a[i]>aver) cout<<a[i]<<" ";	
//	} 	

	//题目：编写一个函数，筛选出整数数组中所有大于某个给定值的元素，并存入一个新数组中。
	//方法1 
//	void saixuan(int *a, int len, int k, int *newarr,int &ii){
//		for(int i=0;i<len;i++){
//			if(a[i] > k) newarr[ii++] = a[i];
//		}
//	}
//	
//	
//int main(){
// 	int a[]={0,1,2,3,-4,5,6,7,8,10};
// 	int len = sizeof(a)/sizeof(a[0]); 
// 	
// 	double k = 0;
// 	
// 	int newarr[len];
// 	int ii=0;
// 	
// 	saixuan(a,len,k,newarr,ii);
// 	
// 	for(int i=0;i<ii;i++) cout<<newarr[i]<<" ";

	//方法2  动态数组1 
//	void saixuan(int *a, int len, int k, vector <int> newarr){   //对应动态数组设置的形参 
//		for(int i=0;i<len;i++){
//			if(a[i] > k) newarr.push_back(a[i]);
//		}
//		for(int x: newarr) cout<<x<<" ";
//	}
//	
//	
//int main(){
// 	int a[]={0,1,2,3,-4,5,6,7,8,10};
// 	int len = sizeof(a)/sizeof(a[0]); 
// 	
// 	double k = 3.5;
// 	
// 	vector <int> newarr;
// 	
// 	saixuan(a,len,k,newarr);  //动态数组作为实参

	//方法2  动态数组2 

//	void saixuan(int *a, int len, int k, vector <int> &new_arr){   //对应动态数组设置的形参  引用传参 
//		for(int i=0;i<len;i++){
//			if(a[i] > k) new_arr.push_back(a[i]);
//		}
//		//for(int x: new_arr) cout<<x<<" ";	
//	}
//	
//	
//int main(){
// 	int a[]={0,1,2,3,-4,5,6,7,8,10};
// 	int len = sizeof(a)/sizeof(a[0]); 
// 	
// 	double k = 5.5;
// 	
// 	vector <int> newarr;
// 	
// 	saixuan(a,len,k,newarr);  //动态数组作为实参
// 	
// 	for(int x: newarr) cout<<x<<" ";  //引用传参  则可以回主函数遍历 


	//输入不确定个数的【0-9】 范围内的数，统计每个数字出现的次数 （-1结束）

//	const int number=10;  //对于程序中出现的多次同一个数字，称为魔术数字，易混淆；好的做法是定义一个常量 
//	int x,a[number]={0};
//	cin>>x;
//	
//	while(x!=-1){
//		if(x>=0 && x<=9) a[x]++;
//		cin>>x;
//	}
//	
//	int i=0;
//	while(i<number){
//		if(a[i]!=0) printf("%d  %d\n",i,a[i]);
//		i++;
//	}
//	
//	for(int i=0;i<number;i++){
//	
//		printf("%d  %d\n",i,a[i]);
//		
//	}

//	 //编写一个函数，在一个整数数组中查找给定值，如果找到返回该值的索引（若有多个仅返回找到的第一个索引），未找到返回-1. 
//	int search(int key, int a[], int len){  //当以数组作为参数时候，须同时带上数组长度； 
//		int ret=-1;
//		for(int i=0;i<len;i++){
//			if(a[i]==key) {ret=i;break;}	
//		}	
//		return ret;   //单一返回出口   好的做法 
//	}
//	

//	int a[]={1,2,3,4,5,6,7,8};
//	int x;
//	cin>>x;
//	
//	int len = sizeof(a)/sizeof(a[0]);
//	
//	int loc = search(x, a, len);  
//	if(loc!= -1) printf("%d 在下标 %d 位置\n",x,loc);
//	else printf("%d 不存在！",x);



 //编写一个函数，计算整数数组中所有偶数元素之和。
// 	int sum(int* a,int len){
//	 	int s=0;
//	 	for(int i=0;i<len;i++) 
//			if(a[i]%2==0) 
//				s+=a[i];
// 		return s;
//	 }
// 	
// 	
// 	int a[]={1,2,3,4,5,6,7,8,10};
// 	int len = sizeof(a)/sizeof(a[0]); 
// 	
// 	cout<<sum(a,len);

	//编写一个函数，去除整数数组中的重复元素，返回去重后数组的长度。假设数组已排序
//	int arr_len(int *a,int len){
// 		if(len==0) return len;
// 		int count=1;
// 		for(int i=0;i<len-1;++i){
// 			if(a[i]!=a[i+1]) count++;
//		 }
//		return count;
//	 }
// 	
// 	
// 	int a[]={1,2,2,2,3,4,5,5,6,7,8,10,10};
// 	int len = sizeof(a)/sizeof(a[0]); 
// 
// 	
// 	cout<<arr_len(a,len);

	//编写一个函数，去除整数数组中的重复元素，得到去重后的数组。假设数组已排序 
	//方法 0  思路： 因为有序，原地去重拷贝，无需声明新数组，节省内存空间。 

//    int remove_dup(int *arr, int len){
//    	
//    	int size=1;  //第一个元素去重后 还是在第一个位置 arr[0]  或理解 ：去不去重 a[0] 的值不变 ； 所以初值 为 1 
//    	for(int i=1;i<len;i++){  	// 从第二个元素开始遍历  即下标 1 开始 
//    		if(arr[i] != arr[i-1]) arr[size++] = arr[i];  //  让每个数和它前面到元素比较  可以避免越界危险 ；把后面的元素往前搬，不会有数据重叠危险 
//		}
//    	return size;	
//	}
//       
//int main(){
//
//    int a[]={1,2,2,2,3,4,5,5,6,7,8,10};
// 	int len = sizeof(a)/sizeof(a[0]); 
//    
//    int new_size = remove_dup(a, len);
//    for(int i=0;i<new_size;i++) cout<<a[i]<<" ";



	//方法 1 常规顺序结构  思路：声明了新数组 b[len]  用于存储去重后的元素
//	int a[]={1,2,2,2,3,4,5,5,6,7,8,10},i;
// 	int len = sizeof(a)/sizeof(a[0]); 
//
//	int b[len],size=0;  //声明了新数组 b[len]  用于存储去重后的元素
//	for(i=0;i<len-1;++i){
//		if(a[i]!=a[i+1]) b[size++]=a[i];  //把数组 a 中不重复的逐一赋值给 b 
//	}
//	b[size++]=a[i];	 //注意：不要忘记最后一个 
// 	//cout<<size<<endl;
// 	for(int i=0;i<size;i++) cout<<b[i]<<" ";

	//方法 2 函数封装结构  思路：原地去重拷贝，无需声明新数组，节省内存空间。
// 	void new_arr(int *a, int len){
// 		int size=1;
//		for(int i=1;i<len;++i){
//			if(a[i]!=a[i-1]) a[size++]=a[i];
//			}
// 		for(int i=0;i<size;i++) cout<<a[i]<<" ";	
//	 }
//
//int main(){
//	int a[]={1,2,2,2,3,4,5,5,6,7,8,10},i;
// 	int len = sizeof(a)/sizeof(a[0]); 
// 	
//	new_arr(a,len);


	//方法 3 函数封装,返回数组(指针) 和方法4 一样  此练习是为 熟悉 返回数组(指针)  

//	int *new_arr(int &size, int *a, int len){
// 		if(len == 0) return 0;
// 		int *b;   //注意这里声明一个新数组(指针) b , 不可以写成数组形式 b[len],而需要写成 指针形式 *b, 方便最后return;  
// 		b[0] = a[0];   // //理解 ：去不去重 a[0] 的值不变, 直接给 b[0]； 所以下面 size初值 为 1 
//		size=1;  // 无需也不可以 int size = 1;  形参里已经声明 有int &size 
// 		for(int i=1;i<len;++i){
// 			if(a[i]!=a[i-1]) b[size++]=a[i];
//		}
//		return b;  //返回此数组指针 
//	 }
//int main(){
//	
//	int a[]={1,2,2,2,3,4,5,5,6,7,8,10},i;
// 	int len = sizeof(a)/sizeof(a[0]); 
// 	
// 	int size=0;
//	int *c=new_arr(size,a,len);  //接收返回数组指针 
//	//cout<<size<<endl;
//	//cout<<c<<endl;
//	
//	for(int i=0;i<size;i++) cout<<c[i]<<" ";


	//方法 4 函数封装,通过参数传递数组指针 

//	void fun(int *new_arr, int &size, int *old_arr, int len){   //注意形参： int *new_arr, int &size,  该函数功能：是把旧数组old_arr去重后的元素给到 new_arr； 处理后形参改变了实参内容 
// 		new_arr[0] = old_arr[0];   // 
//		size=1;  // 无需也不可以 int size = 1;  形参里已经声明 有int &size
// 		for(int i=1;i<len;++i){
// 			if(old_arr[i]!=old_arr[i-1]) new_arr[size++]=old_arr[i];
//		}  
//	 }
//int main(){
//	int old_arr[]={1,2,2,2,3,4,5,5,6,7,8,10},i;
// 	int len = sizeof(old_arr)/sizeof(old_arr[0]); 
// 	
// 	int new_arr[len]; //在主函数中声明一个新数组，用于接收存储处理后的数组元素 
// 	int size=0; //声明变量size  用于接收 处理后的数组元素个数 
//	fun(new_arr, size, old_arr, len); //传参 
//	
//	for(int i=0;i<size;i++) cout<<new_arr[i]<<" ";  //直接使用  这里的size  new_arr 内容在经过函数处理后 均发生了变化 


		//方法 5 原理同方法 4   函数封装,使用动态数组 vector 向量容器实现； 通过引用传参 调用函数，避免返回值拷贝 

//	void re_vec(int *arr, int len, vector <int> &output){   //注意形参设置：避免返回值拷贝，通过引用参数传递 vector , 形参改变了实参内容 
// 		output.push_back(arr[0]);
// 		for(int i=1;i<len;++i){
// 			if(arr[i] != arr[i-1]) output.push_back(arr[i]);
//		}  
//	 }
//	 
//int main(){
//	
//	int arr[]={1,2,2,2,3,4,5,5,6,7,8,10};
// 	int len = sizeof(arr)/sizeof(arr[0]); 
//	
// 	vector<int > result; 
//	re_vec(arr, len, result);//直接把声明的动态数组 result 作为参数 通过引用传参 调用函数，避免返回值拷贝 
//	
//	for(int x: result) cout<<x<<" ";


	//题目：编写一个函数，将一个新元素插入到已排序的整数数组中的合适位置。
	//静态数组方法 1  思路：前提是数组有序，数组插入新元素，通常做法是 从后向前遍历，一一比较，大的都往后搬移一个位置，直到小的，把新元素给到此位置的下一个位置 ，再终止循环 
//	void insert_arr(int *arr, int &len, int new_elem){  //注意： 引用变量 int &len 
//		
//		for(int i=len-1;i>=0;i--){  
//			
//			if(arr[i] >= new_elem) arr[i+1] = arr[i];
//			else {arr[i+1] = new_elem;break;}	
//
//		}
//		len++;  //插入新元素后，记得将长度的值+1 ，通过引用变量返回    
//	}
//	
//	int elem_len(int *arr, int SIZE){
//		int count=0;
//		for(int i=SIZE-1;i>=0;i--)
//			if(arr[i] != 0) count++;
//		return count;
//	}
//	
//	int main(){
//		const int SIZE = 10;
//		int arr[SIZE]= {1,3,4,6,7,8,10,12,13};   //因为待会要插入新元素，所以数组长度设置稍大点  ；若直接置为空 int arr[ ]= {1,3,4,6,7,8,10};  此程序没问题，但不安全，因为越界用到  arr[7]
// 		int len = elem_len(arr,SIZE);    //取出数组中（ 除零外的）实际长度（7）  
// 		
// 		int new_elem;
// 		cin>>new_elem;
// 		
// 		insert_arr(arr,len,new_elem); 
// 		
// 		for(int i=0;i<len;i++)  //这里的 len 值（8）已经改变    
// 			cout<<arr[i]<<" ";

	//题目：编写一个函数，将一个新元素插入到已排序的整数数组中的合适位置。	
	//动态数组方法 2： 思路同上，此用了动态数组，更安全 	
//	void insert_arr(vector <int> &output, int len, int new_elem){  //注意形参中的  vector <int> &output 用于对应 引用调用函数中的 vector <int>实参 
//		
//		for(int i=len-1;i>=0;i--){
//			
//			if(output[i] >= new_elem) output[i+1] = output[i];
//			else {output[i+1] = new_elem;break;}	
//		}
//		for(int i=0;i<len+1;i++)
// 			cout<<output[i]<<" ";
//	}
//	
//	int main(){
//		vector<int> arr = {1,3,4,6,7,8,10};
// 		int len = arr.size();
// 		int new_elem;
// 		cin>>new_elem;
// 		
// 		insert_arr(arr,len,new_elem);


//题目：编写一个函数，找出整数数组中具有最大和的连续子数组，并返回该最大和。动态规划算法 

//	int maxsubsum(vector<int> arr, int len){
//		int currentsum=arr[0];
//		int maxsum=arr[0];
//		for(int i=1;i<len;i++){
//			
//			currentsum=max(arr[i], currentsum+arr[i]); // max(第二个元素，当前和+第二元素之和)    大的给currentsum ; 
//			maxsum=max(maxsum,currentsum);  //max(第一个元素，上面得到的大数)  大的给maxsum 
//		}
//		return maxsum;
//	}
//
//
//	int main(){
//		vector<int> arr = {-2,1,3,-4,-1,2,1,-5,4};
// 		int len = arr.size();
// 		
// 		cout<<maxsubsum(arr,len);


	//题目：编写一个函数，将数组中第 m 个元素到第 n 个元素（包含 m 和 n）进行对调。  典型的对调做法案例 
//	void swap_part_elem(int *a, int size, int m, int n){
//		if(m<0) m=1;
//		if(n>size) n=size;
//		while(m<n){   // 典型的对调做法案例  m n相当于前后指针功能 
//			int temp=a[m-1];
//			a[m-1]=a[n-1];
//			a[n-1]=temp;
//			m++;
//			n--;	
//		}	
//	}
//	
//	
//int main(){
//	
//	int a[] = {1,2,3,4,5,6,7,8,9};
//	int size = sizeof(a)/sizeof(int);
//	int m = -1,n = 6;
//	
//	swap_part_elem(a,size,m,n);
//	
//	for(int x: a) cout<<x<<" ";



	//构造（1--100）素数表 思路：先将所有初值置为1；从2开始 直到100内的 所有2的倍数不是素数，将其置为0；
								 //再3 所有3的倍数不是倍数；并将其置为0 .。。 依次类推
//	const int number=120;
//	int a[number];
//	
//	for(int i=2;i<number;i++) {
//		a[i]=1;
//	}
//	
//	for(int i=2;i<number;i++){
//	//	if(a[i]) {
//			for(int j=2;i*j<number;j++){
//				a[i*j]=0;	
//			}	
//	//	}	
//	}
//	
//	for(int i=2;i<number;i++) {
//		if(i%10==0) cout<<endl;
//		if(a[i]) cout<<i<<"\t";
//	}


	//题目描述：编写一个函数，使用冒泡排序算法对整数数组进行排序。

//void bubblesort(int *a, int len){
//	for(int i=0;i<len-1;i++){
// 		for(int j=i+1;j<len;j++){  
// 			if(a[i] > a[j]) {  //外层每个元素 分别与内层每个元素比较 
// 				int temp = a[i];
// 				a[i] = a[j];
// 				a[j] =temp;
//			 }
// 			
//		 }
//	}	
//	}

//void bubblesort2(int *a, int len){
//	for(int i=0;i<len-1;i++){   比较轮次 
//		bool flag = false;   //优化 
// 		for(int j=0;j<len-1-i;j++){  //每轮比较次数 
// 			if(a[j] > a[j+1]) {   // 内层比较 
// 				flag= true;
// 				int temp = a[j];
// 				a[j] = a[j+1];
// 				a[j+1] =temp;
//			 }	
//		 }
//		if(!flag) break;  //若本轮无交换，则说明有序 
//	}
//	}	
//int main(){
//
//	int a[]={1,-2,3,-4,-6,7,8,10,-55};
// 	int len = sizeof(a)/sizeof(a[0]); 
// 	
//	bubblesort2(a,len);
//	
//	for(int x: a) cout<<x<<" ";


	//题目描述：编写一个函数，将两个有序整数数组合并为一个新的有序数组。


//int main(){
//	
//	int a[] = {1,4,5,8};
//	int b[] = {0,6,10};
//	int len_a = sizeof(a)/sizeof(a[0]);
//	int len_b = sizeof(b)/sizeof(b[0]);
//	
//	vector <int> newarr;
//	
//	for(int i=0;i<len_a;i++){
//		for(int j=0;j<len_b;j++){
//			
//			if(a[i] > b[j])  newarr.push_back(b[j]);
//			else {newarr.push_back(a[i]);break;}
//		}
//		
//	}
//	
//	for(int x: newarr) cout<<x<<" ";





	//-std=c++11  编译器加 此选项  使编译器支持如下新特性 
//	1、auto 关键字 （自动类型推导）  auto x = 42;
//	2、范围 for 循环  for(auto x: vec)  cout<<x;
//	3、Lambda 表达式  [](){}    示例：sort(vec.begin(),vec.end(),[](int a, int b){return a>b;}); 
//	4、移动语义  move 减少拷贝开销
//	5、智能指针 unique_ptr, shared_ptr 



	return 0;
}