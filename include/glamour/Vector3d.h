//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * ����������� ������ Vector3d
 * @author <a href="LeonidShevtsov@gmail.com">������ ������</a>
 * @version 0.1
 * @date 23.08.2006
 */
#ifndef GLA_Vector3d_h
#define GLA_Vector3d_h

#include "Vector2d.h"

namespace Glamour
{
    /// ���������� ������
    /**
     * @todo �������� ��� ���������
     * @author <a href="mailto:LeonidShevtsov@gmail.com">������ ������</a>
     * @version 0.3
     * ����� ���������� ��������.
     * @date 27.09.2006
     * !!! ����� !!!
     * ��������� �������� & � ^ ����� ������� ���������, ���
     * + � -, �� �������� ^ (��������� ���������) �������� ��
     * *. �������� & (��������� ���������) �� ��� ������, ��� ���
     * ���������
     * @code
     * float f,a;
     * Vector3d v1,v2;
     * f=a+v1&v2; // f = (a+v1)&v2;
     * @endcode
     * ������� �������� ����� � �������, ��� ����������, � ���������
     * @code
     * Vector3d u,q,v1,v2;
     * q=u+v1^v2; // q = (u+v1)^v2;
     * @endcode
     * ������ ��������� � �� ������� ������.
     *
     * ����� ����� �������� ��� ��������� ����������� ���:
     * @code
     * x=u+v1*v2; // ��������� ���������
     * x=a+(v1&v2); //��������� ���������
     * @endcode
     * @version 0.2
     * ����� �������� ��������: norm,normSq,normalise
     * @date 11.09.2006
     * @version 0.1
     * @date 23.08.2006
     */
    class Vector3d
    {
    public:
//==========================================================
///@name ����������� ��������
///@{
        ///����������� �� ���������
        /**
         * ������� ������� ������
         */
        Vector3d();
        ///����������� �����������
        /**
         * @param from �������� ������
         */
        Vector3d(const Vector3d& from);
        ///�������� ������������
        /**
         * @param from �������� ������
         * @return ������ ������
         */
        Vector3d& operator=(const Vector3d& from);
        ///����������
        ~Vector3d();
///@}
//==========================================================
///@name ������������
///@{
    ///������������ �����������
    Vector3d(const float f);
    Vector3d(const float X,const float Y,const float Z);
    Vector3d(const Vector2d& v);
///@}
//==========================================================
///@name ��������
///@{
    ///����� (�����)
    float norm() const;
    ///����� � ��������
    float normSq() const;
///@}
//==========================================================
///@name ���������
///@{
    operator float*();
    ///��������
    friend Vector3d operator+(const Vector3d& u,const Vector3d& v);
    ///���������
    friend Vector3d operator-(const Vector3d& u,const Vector3d& v);
    ///��������� �� ������
    friend Vector3d operator*(const Vector3d& v,const float f);
    ///��������� �� ������
    friend Vector3d operator*(const float f,const Vector3d& v);
    ///��������� ���������
    friend Vector3d operator*(const Vector3d& u,const Vector3d& v);
    ///������� �� ������
    friend Vector3d operator/(const Vector3d& v,const float f);
    ///�������� ������
    friend Vector3d operator-(const Vector3d& v);
    ///��������� ������������
    friend float operator&(const Vector3d& u,const Vector3d& v);

    ///��������� �� ������
    friend Vector3d& operator*=(Vector3d& v,const float f);
    friend Vector3d& operator+=(Vector3d& u,const Vector3d& v);
///@}
//==========================================================
///@name ������
///@{
    Vector3d& normalize();
    Vector3d getNormalize() const;
///@}
//==========================================================
///@name �������
///@{
    static Vector3d randomColor();
    static Vector3d randomSphereDelta(float radius);
    static Vector3d randomCubeDelta(float side);
///@}
//==========================================================
///@name �����
///@{
    public:
    ///����������
    float x;
    ///����������
    float y;
    ///����������
    float z;
    protected:
    private:
///@}
//==========================================================
    };
    ///�������� �������� ��� ������ Vector3d
    typedef Vector3d vec3;
}
#endif
