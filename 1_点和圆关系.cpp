#include<iostream>
#include "Point.hpp"
#include "Circle.hpp"

void ispointincircle(Point &p, Circle &c){
    float distance = (p.getX()-c.getCenter().getX())*(p.getX()-c.getCenter().getX())+
    (p.getY()-c.getCenter().getY())*(p.getY()-c.getCenter().getY());

    if(distance>c.getR()*c.getR()){
        std::cout<<"点在圆外"<<std::endl;
    }
    else if(distance==c.getR()*c.getR()){
        std::cout<<"点在圆上"<<std::endl;
    }
    else{
        std::cout<<"点在圆内"<<std::endl;
    }   


}

int main(){

    Circle c;
    Point c_center;
    c_center.set(0,0);
    c.set(c_center, 5);
    Point p;    
    p.set(3,4);
    ispointincircle(p,c);
    return 0;
}