typedef unsigned char BYTE;

struct PIDState {
    double px;
    double ix;
    double dx;
    double p;
    double i;
    double d;
    double v;
    double target;
    double out;
}

void addData(struct PIDState *in, double data) {
    double newP = data - in->v;
    in->v = data;
    double newI = newP - in->p;
    in->p = newP;
    in->d = newI - in->i;
    in->i = newI;
    in->out = (in->px * in->p) + (in->ix * in->i) + (in->dx * in->d);
}

void initData(struct PIDState *in, double data) {
    in->v = data;
    in->p = in->target - data;
    in->i = 0;
    in->d = 0;
    in->out = in->px * in->p;
}

struct NavPoint {
    double x;
    double y;
    double z;
    BYTE isDeadStop;
}

struct NavPath {
    struct NavPoint *data;
    unsigned int size;
}

