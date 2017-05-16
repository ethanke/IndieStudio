//
// WheelHit.hpp for  in /Users/vicostudio/Documents/Shared/TEK2/CPP/cpp_indie_studio_/includes/CarSystem/
//
// Made by Sousa Victor
// Login   <sousa_v@epitech.eu>
//
// Started on  Tue May 16 12:27:19 2017 Sousa Victor
// Last update Tue May 16 12:28:19 2017 Sousa Victor
//

#ifndef WHEELHIT_HPP_
#define WHEELHIT_HPP_

#include "Vector3.hpp"

namespace indie {

    class WheelHit {

    public:
        WheelHit();
        ~WheelHit();

        // const Collider &getCollider() const;
        // void setCollider(const Collider &collider);

        float getForce() const;
        void setForce(float force);

        const Vector3 &getForwardDir() const;
        void setForwardDir(const Vector3 &forwardDir);

        float getForwardSlip() const;
        void setForwardSlip(float forwardSlip);

        const Vector3 &getNormal() const;
        void setNormal(const Vector3 &normal);

        const Vector3 &getPoint() const;
        void setPoint(const Vector3 &point);

        const Vector3 &getSidewaysDir() const;
        void setSidewaysDir(const Vector3 &sidewaysDir);

        float getSidewaysSlip() const;
        void setSidewaysSlip(float sidewaysSlip);


    private:
        //Collider _collider;
        float _force;
        Vector3 _forwardDir;
        float _forwardSlip;
        Vector3 _normal;
        Vector3 _point;
        Vector3 _sidewaysDir;
        float _sidewaysSlip;
    };

}

#endif /*WHEELHIT_HPP_*/
