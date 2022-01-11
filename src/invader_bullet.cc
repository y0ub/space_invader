#include "invader_bullet.hpp"

/*****************************************/
/* date: 2022/01/11                      */
/* what: constructor                     */
/*****************************************/
space_invader::
InvaderBullet::InvaderBullet (const int invader_column)
{
  resize_invader_bullet (invader_column);
}

/*****************************************/
/* date: 2022/01/11                      */
/* what: show function name              */
/*****************************************/
void space_invader::
InvaderBullet::resize_invader_bullet (
    const int invader_column)
{
  invader_bullet_.resize (invader_column);
}

/*****************************************/
/* date: 2022/01/11                      */
/* what: getter for invader_bullet_      */
/*****************************************/
const std::vector<space_invader::InvaderBullet::BulletStatus>
space_invader::InvaderBullet::get_invader_bullet ()
{
  return invader_bullet_;
}

/*****************************************/
/* date: 2022/01/11                      */
/* what: set status of invader_bullet_   */
/*****************************************/
void space_invader::
InvaderBullet::shoot_bullet (
    const int x, const int y, const int invader_x, const int invader_y)
{
  if (invader_bullet_.at(x).is_shoot_)
    return ;
  invader_bullet_.at(x).x_        = invader_x;
  invader_bullet_.at(x).y_        = invader_y + 1;
  invader_bullet_.at(x).is_shoot_ = true;
}

/*****************************************/
/* date: 2022/01/11                      */
/* what: show function name              */
/*****************************************/
void space_invader::
InvaderBullet::move_bullet (const int screen_height)
{
  int n = invader_bullet_.size ();
  for (int i = 0; i < n; ++i) {
    if (!invader_bullet_.at(i).is_shoot_)
      continue;
    if (screen_height - 1 > invader_bullet_.at(i).y_)
      ++invader_bullet_.at(i).y_;
    else
      invader_bullet_.at(i).is_shoot_ = false;
  }
}
