#include "player.hpp"

/*****************************************/
/* date: 2022/01/11                      */
/* what: constructor                     */
/*****************************************/
space_invader::Player::Player (const int height, const int width)
{
  point.x_ = width  / 2;
  point.y_ = height - 2;
}

/*****************************************/
/* date: 2022/01/10                      */
/* what: operate player position         */
/*****************************************/
void space_invader::
Player::move_player (const char c, const int screen_width)
{
  switch (c) {
    case 'a':
      point.x_ = std::max (0, point.x_ - 1);
      break;
    case 'd':
      point.x_ = std::min (screen_width - 1, point.x_ + 1);
      break;
    case 'k':
      player_bullet.shoot_bullet (point.x_, point.y_);
      break;
  }
}

/*****************************************/
/* date: 2022/01/10                      */
/* what: getter for position of player   */
/*****************************************/
space_invader::Player::Point
space_invader::Player::get_player_point ()
{
  return point;
}
