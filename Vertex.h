#ifndef VERTEX_H
#define VERTEX_H

class Vertex{
    private:
       int index;
       int degree;
       int distance;
    public:
        Vertex();
        int getIndex();
        int getDegree();
        int getDistance();
        void setIndex(int);
        void setDegree(int);
        void setDistance();
};

#endif
