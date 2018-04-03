#include <pthread.h>
#include <iostream>
#include <mutex>
#include <condition_variable>
class Fork
{
    public:

        void take(){
            std::unique_lock<std::mutex> l(mutex1);
            var1.wait(l, [this](){return isFree == true;});
            isFree = false;
            l.unlock();
        }
        void release(){
            std::unique_lock<std::mutex> l(mutex1);
            isFree = true;
            l.unlock();
            var1.notify_one();
        }
        bool getIsFree(){return isFree;}
        void setIsFree(bool val){isFree = val;}

        Fork(int id);
        ~Fork();

    protected:
    private:
        int Fid;
        std::mutex mutex1;
        std::condition_variable var1;
        bool isFree;
};
