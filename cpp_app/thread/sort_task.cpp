#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <list>
#include <chrono> 
#include <algorithm>

#define N 1000
using namespace std;

volatile int g_count = 0;   // volatile 修饰的变量只能有一个线程可以访问

struct Task
{
    int a[N];
};

mutex g_listMutex;
list<Task>  g_listTask;

void generate_vector()
{
    while(1)
    {
        g_listMutex.lock();

        if(g_listTask.size()<20)  // 防止内存溢出
        {
            Task task;
            for(int i=0; i<N; i++)
            {
                task.a[i] = rand() % 65535;
            }
            g_listTask.push_back(task);
        }else{
            // std::cout << "开始休眠" << std::endl;  
            // std::this_thread::sleep_for(std::chrono::seconds(1)); // 休眠 3 秒  
            // std::cout << "休眠结束" << std::endl;  
        }
        g_listMutex.unlock();
    }
}

// 选择排序
void select_sort()
{
    Task task;
    bool bFind = false;
    int count = 0;
    while(1)
    {
        g_listMutex.lock();
        if(g_listTask.size() > 0)  // 防止内存溢出
        {
            task = g_listTask.front();
            bFind = true;
            g_listTask.pop_front();
        }else{
            bFind = false; 
        }
        g_listMutex.unlock();

        if(bFind)
        {
            int min_idx;
            for (int i = 0; i < N-1; i++) {  
                min_idx = i;  
                for (int j = i+1; j < N; j++)  
                    if (task.a[j] < task.a[min_idx])  
                        min_idx = j;  
                int temp = task.a[min_idx];  
                task.a[min_idx] = task.a[i];  
                task.a[i] = temp;
            }  

            count++;
            cout << "完成" << count << "次选择排序\n";
        }

        if(count==500) break;
    }
}



// 冒泡
void pp_sort()
{
    Task task;
    bool bFind = false;
    int count = 0;
    while(1)
    {
        g_listMutex.lock();
        if(g_listTask.size() > 0)  // 防止内存溢出
        {
            task = g_listTask.front();
            bFind = true;
            g_listTask.pop_front();
        }else{
            bFind = false; 
        }
        g_listMutex.unlock();

        if(bFind)
        {
            // sort(task.a.begin(), task.a.end());
            for(int i=0; i<N; i++)
            {
                for(int j=0; j<N-i-1; j++)
                {
                    if(task.a[j] > task.a[j+1])
                    {
                        int temp = task.a[j];
                        task.a[j] = task.a[j+1];
                        task.a[j+1] = temp;
                    }
                }
            }
            count++;
            cout << "完成" << count << "次冒泡排序\n";
        }
        if(count==500) break;
    }
}

// 快排
void quick_sort()
{
    Task task;
    bool bFind = false;
    int count = 0;
    while(1)
    {
        g_listMutex.lock();
        if(g_listTask.size() > 0)  // 
        {
            task = g_listTask.front();
            bFind = true;
            g_listTask.pop_front();
        }else{
            bFind = false; 
        }
        g_listMutex.unlock();

        if(bFind)
        {
            sort(task.a, task.a+N);
            count++;
            cout << "完成" << count << "次快速排序\n";
        }
        if(count==500) break;
    }
}



int main()
{
    thread t1(generate_vector);
    thread t2(quick_sort);
    thread t3(pp_sort);
    thread t4(select_sort);

    t1.join();
    t3.join();
    t4.join();
    t2.join();

    return 0;
}