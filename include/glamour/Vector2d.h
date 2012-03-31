//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * ����������� ������ Vector2d
 * @author <a href="LeonidShevtsov@gmail.com">������ ������</a>
 * @version 0.1
 * @date 16.11.2006
 */
#ifndef GLA_Vector2d_h
#define GLA_Vector2d_h
namespace Glamour
{
    /// ��������� ������
    /**
     * !!! ����� - ��� ��������� �� Vector2d. ����� ���� ����������!
     * @todo �������� ��� ���������
     * @author <a href="mailto:LeonidShevtsov@gmail.com">������ ������</a>
     * @version 0.1
     * @date 16.11.2006
     */
    class Vector2d
    {
    public:
//==========================================================
///@name ����������� ��������
///@{
        ///����������� �� ���������
        /**
         * ������� ������� ������
         */
        Vector2d();
        ///����������� �����������
        /**
         * @param from �������� ������
         */
        Vector2d(const Vector2d& from);
        ///�������� ������������
        /**
         * @param from �������� ������
         * @return ������ ������
         */
        Vector2d& operator=(const Vector2d& from);
        ///����������
        ~Vector2d();
///@}
//==========================================================
///@name ������������
///@{
    ///������������ �����������
    Vector2d(const float f);
    Vector2d(const float X,const float Y);
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
    friend Vector2d operator+(const Vector2d& u,const Vector2d& v);
    ///���������
    friend Vector2d operator-(const Vector2d& u,const Vector2d& v);
    ///��������� �� ������
    friend Vector2d operator*(const Vector2d& v,const float f);
    ///��������� �� ������
    friend Vector2d operator*(const float f,const Vector2d& v);
    ///��������� ���������
    friend float operator*(const Vector2d& u,const Vector2d& v);
    ///������� �� ������
    friend Vector2d operator/(const Vector2d& v,const float f);
    ///�������� ������
    friend Vector2d operator-(const Vector2d& v);
    ///��������� ������������
    friend float operator&(const Vector2d& u,const Vector2d& v);

    ///��������� �� ������
    friend Vector2d& operator*=(Vector2d& v,const float f);
    friend Vector2d& operator+=(Vector2d& u,const Vector2d& v);
///@}
//==========================================================
///@name ������
///@{
    Vector2d& normalize();
    Vector2d getNormalize() const;
///@}
//==========================================================
///@name �������
///@{
    static Vector2d randomCircleDelta(float radius);
    static Vector2d randomSquareDelta(float side);
///@}
//==========================================================
///@name �����
///@{
    public:
    ///����������
    float x;
    ///����������
    float y;
///@}
//==========================================================
    };
    ///�������� �������� ��� ������ Vector2d
    typedef Vector2d vec2;
}
#endif
