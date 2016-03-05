#ifndef CAMERAKINECT2_H
#define CAMERAKINECT2_H

#include "camera.h"

#include "Kinect.h"

class CameraKinect2 : public Camera
{
public:
    CameraKinect2();
    ~CameraKinect2();

    bool initialize(const char* path = nullptr);
    bool getNextFrame(InputData *input);

    const char* m_moduleTag = "KN2";
private:
    template<class Interface>
    inline void SafeRelease( Interface *& pInterfaceToRelease )
    {
        if( pInterfaceToRelease != NULL ){
            pInterfaceToRelease->Release();
            pInterfaceToRelease = NULL;
        }
    }

    IKinectSensor*              m_sensor;
    ICoordinateMapper*          m_coordMapper;
    IMultiSourceFrameReader*    m_sourceReader;
};

#endif // CAMERAKINECT2_H
