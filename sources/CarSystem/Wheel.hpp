//
// Wheel.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/sources/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Tue May 16 12:29:56 2017 Sousa Victor
// Last update Tue May 16 12:30:21 2017 Sousa Victor
//

#ifndef WHEELHPP_
#define WHEELHPP_

namespace indie {

    class Wheel {

    public:
        Wheel();
        Wheel(const Wheel &rhs);
        ~Wheel();
        Wheel &operator =(const Wheel &rhs);


        // // WheelCollider const &getWheelCollider() const;
        // // void setWheelCollider(WheelCollider const &wheelCollider);
        //
        // Transform const &getWheelTransform() const;
        // void setWheelTransform(Transform const &wheelTransform);
        //
        // Transform const &getCaliperTransform() const;
        // void setCaliperTransform(Transform const &caliperTransform);

        bool getSteer() const;
        void setSteer(bool steer);

        bool getDrive() const;
        void setDrive(bool drive);

        bool getBrake() const;
        void setBrake(bool brake);

        bool getHandBrake() const;
        void setHandBrake(bool handbrake);


    private:
        // WheelCollider _wheelCollider;
        // Transform _wheelTransform;
        // Transform _caliperTransform;
        bool _steer;
        bool _drive;
        bool _brake;
        bool _handbrake;

    };

}

#endif /*WHEEL_HPP_*/
