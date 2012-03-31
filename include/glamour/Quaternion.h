//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * ����������� ������ Quaternion
 * @author <a href="mailto:LeonidShevtsov@gmail.com">������ ������</a>
 * @version 0.1
 * @date 27.09.2006
 */
#ifndef GLA_Quaternion_h
#define GLA_Quaternion_h

#include "Vector3d.h"
#include "Matrix4x4.h"
namespace Glamour
{
    /// ����������
    /**
     * ����������� ������������ ��� �������� ���������
     * @author <a href="mailto:LeonidShevtsov@gmail.com">������ ������</a>
     * @version 0.1
     * @date 27.09.2006
     */
    class Quaternion
    {
    public:
//==========================================================
///@name ����������� ��������
///@{
        ///����������� �� ���������
        Quaternion();
        ///����������� �����������
        /**
         * @param from �������� ������
         */
        Quaternion(const Quaternion& from);
        ///�������� ������������
        /**
         * @param from �������� ������
         * @return ������ ������
         */
        Quaternion& operator=(const Quaternion& from);
        ///����������
        ~Quaternion();
///@}
//==========================================================
///@name ������������
///@{
    Quaternion(const Vector3d& v);
    Quaternion(const Vector3d& v,float w);
    Quaternion(float x,float y,float z,float w);
///@}
//==========================================================
///@name ��������
///@{
    float norm() const;
    float magnitude() const;
///@}
//==========================================================
///@name ���������
///@{
    friend Quaternion operator-(const Quaternion& q);
    friend Quaternion operator!(const Quaternion& q);
    friend Quaternion operator+(const Quaternion& q1,const Quaternion& q2);
    friend Quaternion operator*(const Quaternion& q,float f);
    friend Quaternion operator/(const Quaternion& q,float f);
    friend Quaternion operator*(float f,const Quaternion& q);
    friend Quaternion operator*(const Quaternion& q1,const Quaternion& q2);

    Quaternion& operator*=(const Quaternion& q1);
    operator Vector3d();
///@}
//==========================================================
///@name ������
///@{
    ///���������� ������� ������������ �������� ���
    /**
     * @param angle ���� ��������.
     * @param axis ��� ��������.
     */
    void makeRotate(float angle,const Vector3d& axis);
    ///���������� ������� ������������ ��� X
    /**
     * @param angle ���� �������� (���).
     */
    void makeRotateX(float angle);
    ///���������� ������� ������������ ��� Y
    /**
     * @param angle ���� �������� (���).
     */
    void makeRotateY(float angle);
    ///���������� ������� ������������ ��� Z
    /**
     * @param angle ���� �������� (���).
     */
    void makeRotateZ(float angle);
    ///������� ������� ��� ��������
    /**
     * @return ������������� �������
     */
    Matrix4x4 toMatrix();
    ///��������� �������� ������� � �������
    Vector3d applyToVector(const Vector3d& v);
///@}
//==========================================================
///@name �������
///@{
    static Quaternion createRotate(float angle,const Vector3d& axis);
    static Quaternion createRotateX(float angle);
    static Quaternion createRotateY(float angle);
    static Quaternion createRotateZ(float angle);
///@}
//==========================================================
///@name �����
///@{
public:
    ///��������� �����
    float w;
    ///��������� �����
    Vector3d v;
    protected:
    private:
///@}
//==========================================================
    };
    ///�������� ��� ���� ��� �����������
    typedef Quaternion quat;
}
#endif
