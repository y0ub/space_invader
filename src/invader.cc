#include "invader.hpp"

/*****************************************/
/* date: 2022/01/08                      */
/* what: constructor                     */
/*       set size of invader_array_      */
/*       determin first invader position */
/*****************************************/
space_invader::Invader::Invader ()
{
  resize_invader_array_ ();
  set_first_position_of_invader_array_ ();
  prepare_directions_ ();

  InvaderBullet inv (INVADER_COLUMN_); 
  invader_bullet_ = inv;
}

/*****************************************/
/* date: 2022/01/08                      */
/* what: look at this function name      */
/*****************************************/
void space_invader::
Invader::resize_invader_array_ ()
{
  invader_array_.resize (INVADER_ROW_);
  for (int i = 0; i < INVADER_ROW_; ++i)
    invader_array_.at(i).resize (INVADER_COLUMN_);
}

/*****************************************/
/* date: 2022/01/11                      */
/* what: determin the initial value of   */
/*       invader_array_                  */
/*****************************************/
void space_invader::
Invader::set_first_position_of_invader_array_ ()
{
  for (int i = 0; i < INVADER_ROW_; ++i) {
    for (int j = 0; j < INVADER_COLUMN_; ++j) {
      invader_array_.at(i).at(j).y_      = i * 2;
      invader_array_.at(i).at(j).x_      = j * 2;
      invader_array_.at(i).at(j).is_dead_ = false;
    }
  }
}

/*****************************************/
/* date: 2022/01/08                      */
/* what: operate directions_             */
/*****************************************/
void space_invader::Invader::prepare_directions_ ()
{
  directions_.push_back (std::make_pair ( 1, 0));
  directions_.push_back (std::make_pair ( 0, 1));
  directions_.push_back (std::make_pair (-1, 0));
  invader_direction_ = DIRECTION_RIGHT_;
}

/*****************************************/
/* date: 2022/01/08                      */
/* what: getter for invader_array_       */
/*****************************************/
const std::vector<std::vector<space_invader::Invader::InvaderStatus> >
space_invader::Invader::get_invader_array ()
{
  return invader_array_;
}

/*****************************************/
/* date: 2022/01/08                      */
/* what: change point of                 */
/*       Invader::invader_array_         */
/*****************************************/
void space_invader::Invader::move_invaders (
    const int screen_height, const int screen_width)
{
  int next_invader_direction = invader_direction_;
  for (int i = 0; i < INVADER_ROW_; ++i) {
    for (int j = 0; j < INVADER_COLUMN_; ++j) {
      if (invader_array_.at(i).at(j).is_dead_)
        continue;
      change_point_of_invader_array (i, j);
      next_invader_direction = get_next_invader_direction (
          i, j, screen_height, screen_width, next_invader_direction);
    }
  }
  invader_direction_ = next_invader_direction;
}

/*****************************************/
/* date: 2022/01/l1                      */
/* what: look at this function name      */
/*****************************************/
void space_invader::
Invader::change_point_of_invader_array (const int i, const int j)
{
  invader_array_.at(i).at(j).x_ +=
    directions_.at(invader_direction_).first;
  invader_array_.at(i).at(j).y_ +=
    directions_.at(invader_direction_).second;
}

/*****************************************/
/* date: 2022/01/08                      */
/* what: determin invader direction      */
/*****************************************/
int space_invader::Invader::get_next_invader_direction (
    const int i,
    const int j,
    const int screen_height,
    const int screen_width,
          int next_invader_direction)
{
  switch (invader_direction_) {
    case DIRECTION_RIGHT_:
      if (screen_width - 1 <=
          invader_array_.at(i).at(j).x_)
        next_invader_direction = DIRECTION_DOWN_;
      break;
    case DIRECTION_DOWN_:
      if (screen_width - 1 <=
          invader_array_.at(i).at(j).x_)
        next_invader_direction = DIRECTION_LEFT_;
      if (0 >= invader_array_.at(i).at(j).x_)
        next_invader_direction = DIRECTION_RIGHT_;
      break;
    case DIRECTION_LEFT_:
      if (0 >= invader_array_.at(i).at(j).x_)
        next_invader_direction = DIRECTION_DOWN_;
      break;
  }
  return next_invader_direction;
}

/*****************************************/
/* date: 2022/01/08                      */
/* what: substitution                    */
/*       invader_array_[y][x]            */
/*       for zero                        */
/*****************************************/
void space_invader::
Invader::kill_invader (const int x, const int y)
{
  invader_array_.at(y).at(x).is_dead_ = true;
}
