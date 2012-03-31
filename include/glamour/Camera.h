//$CopyrightMessageStart$
//$CopyrightMessageEnd$
/**
 * @file
 * ����������� ������ Camera
 * @author <a href="mailto:LeonidShevtsov@gmail.com">������ ������</a>
 * @version 0.1
 * @date 11.09.2006
 */
#ifndef GLA_Camera_h
#define GLA_Camera_h

#include "Vector3d.h"
#include "Matrix4x4.h"
#include "Quaternion.h"
namespace Glamour
{
    /// ������
    /**
     * ������� ����� "������". ��������� ��������, ��������� � ����������� ������. �������� �������������
	 * ������ ���� ����������� � ����������� (��. PerspectiveCamera).
     * @author <a href="mailto:LeonidShevtsov@gmail.com">������ ������</a>
     * @todo fix the quaternion issues - dont need rot OR uvn anymore
     * @version 0.1
     * @date 11.09.2006
     */
    class Camera
    {
    public:
//==========================================================
///@name ����������� ��������
///@{
        ///����������� �� ���������
        Camera();
        ///����������� �����������
        /**
         * @param from �������� ������
         */
        Camera(const Camera& from);
        ///�������� ������������
        /**
         * @param from �������� ������
         * @return ������ ������
         */
        Camera& operator=(const Camera& from);
        ///����������
        virtual ~Camera();
///@}
//==========================================================
///@name ������������
///@{
	///C������ ������ � ��������� �����������
	/**
	 * @
	 */
    Camera(const vec3& _pos,const vec3& _dir,const vec3& _up);
///@}
//==========================================================
///@name ��������
///@{
///@}
//==========================================================
///@name ������
///@{
    virtual void build()=0;
    virtual void buildView();
    void apply();
    void resetView();
///@}
//==========================================================
///@name �������
///@{
///@}
//==========================================================
///@name �����
///@{
    protected:
    public:
        vec3 p;
        vec3 u;//up (y)
        vec3 v;//right (x)
        vec3 n;//forward (z)
        quat rot;
        mat4 projection;
        mat4 modelview;
///@}
//==========================================================
    };
}
#endif
