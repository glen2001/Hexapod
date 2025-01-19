#ifndef LEG
#define LEG

class leg {
    private:
        int SHOULDER_ADDRESS, ELBOW_ADDRESS, WRIST_ADRESS;
        
    public:
        int SHOULDER_ANGLE, ELBOW_ANGLE, WRIST_ANGLE;
        int* GET_ANGLES();
        void SET_ANGLES(int SHOULDER_ANGLE, int ELBOWP_ANGLE, int WRIST_ANGLE);
        void MOVE_IK(int x, int y, int z);       
};


#endif