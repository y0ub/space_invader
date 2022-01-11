#include "player_bullet.hpp"

/*******************************************/
/* date: 2022/01/11                        */
/* what: getter for bullet_status          */
/*******************************************/
space_invader::PlayerBullet::BulletStatus
space_invader::PlayerBullet::get_player_bullet_status ()
{
  return bullet_status;
}

/*******************************************/
/* date: 2022/01/11                        */
/* what: prepare bullet for shoot          */
/*******************************************/
void space_invader::
PlayerBullet::shoot_bullet (const int x, const int y)
{
  bullet_status.x_ = x;
  bullet_status.y_ = y;
  bullet_status.is_shoot_ = true;
}

/*******************************************/
/* date: 2022/01/11                        */
/* what: change player bullet point        */
/*******************************************/
void space_invader::
PlayerBullet::move_bullet ()
{
  if (bullet_status.is_shoot_ &&
      0 < bullet_status.y_) {
    --bullet_status.y_;
  }
  else {
    bullet_status.is_shoot_ = false;
  }
}

/*******************************************/
/* date: 2022/01/11                        */
/* what: show function name                */
/*******************************************/
void space_invader::
PlayerBullet::delete_bullet ()
{
  bullet_status.is_shoot_ = false;
}
