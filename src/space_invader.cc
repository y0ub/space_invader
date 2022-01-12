#include "space_invader.hpp"

/*******************************************/
/* date: 2022/01/10                        */
/* what: constructor                       */
/*******************************************/
space_invader::SpaceInvader::SpaceInvader ()
{
  last_clock_ = clock ();
  space_invader::Player p (screen.SCREEN_HEIGHT_, screen.SCREEN_WIDTH_);
  player = p;
  kill_invader_count = 0;
  lose_flag = false;
}

/*******************************************/
/* date: 2022/01/10                        */
/* what: look at this function name        */
/* why : call flexibly                     */
/*       screen::print_screen              */
/*******************************************/
void space_invader::SpaceInvader::call_print_screen ()
{
  screen.print_screen (invader, player);
}

/*******************************************/
/* date: 2022/01/10                        */
/* what: is match between two points       */
/*******************************************/
bool space_invader::SpaceInvader::is_intersect_two_points (
    const int x_1, const int y_1, const int x_2, const int y_2)
{
  return (x_1 == x_2) && (y_1 == y_2);
}

/*******************************************/
/* date: 2022/01/10                        */
/* what: operate inaveder array            */
/*******************************************/
void space_invader::SpaceInvader::kill_invader (
    const int bullet_x, const int bullet_y)
{
  auto invader_array = invader.get_invader_array ();
  for (int i = 0; i < invader.INVADER_ROW_; ++i) {
    for (int j = 0; j < invader.INVADER_COLUMN_; ++j) {
      if (invader_array.at(i).at(j).is_dead_)
        continue;

      if (is_intersect_two_points (
            bullet_x,
            bullet_y,
            invader_array.at(i).at(j).x_,
            invader_array.at(i).at(j).y_)) {
        kill_invader_processing (i, j);
        goto RETURN_FROM_SPACE_INVADER_KILL_INVADER;
      }
    }
  }
RETURN_FROM_SPACE_INVADER_KILL_INVADER:
  call_print_screen ();
}

/*******************************************/
/* date: 2022/01/11                        */
/* what: look at this function name        */
/*******************************************/
void space_invader::
SpaceInvader::kill_invader_processing (const int i, const int j)
{
  invader.kill_invader (j, i);
  player.player_bullet.delete_bullet ();
  ++kill_invader_count;
}


/*******************************************/
/* date: 2022/01/11                        */
/* what: if intersect player and           */
/*       invader, game over.               */
/*******************************************/
void space_invader::
SpaceInvader::kill_player (
    const int bullet_x, const int bullet_y)
{
  auto point = player.get_player_point ();
  if (is_intersect_two_points (
        point.x_, point.y_, bullet_x, bullet_y))
    lose_flag = true;
}

/*******************************************/
/* date: 2022/01/10                        */
/* what: move player_bullet and            */
/*       kill invader                      */
/*******************************************/
void space_invader::SpaceInvader::player_bullet_processing ()
{
  player.player_bullet.move_bullet ();
  auto player_bullet_status =
    player.player_bullet.get_player_bullet_status ();
  if (player_bullet_status.is_shoot_) {
    kill_invader (player_bullet_status.x_, player_bullet_status.y_);
  }
}

/*******************************************/
/* date: 2022/01/11                        */
/* what: look at this function name        */
/*******************************************/
void space_invader::
SpaceInvader::invader_bullet_processing ()
{
  invader.invader_bullet_.move_bullet (screen.SCREEN_HEIGHT_);
  auto invader_bullet =
    invader.invader_bullet_.get_invader_bullet ();
  for (int i = 0; i < invader.INVADER_COLUMN_; ++i) {
    if (invader_bullet.at(i).is_shoot_) {
      kill_player (invader_bullet.at(i).x_, invader_bullet.at(i).y_);
      if (lose_flag)
        return ;
    }
  }
}

/*******************************************/
/* date: 2022/01/10                        */
/* what: main processing                   */
/*******************************************/
void space_invader::SpaceInvader::game_processing ()
{
  int count = 0;
  call_print_screen ();
  while (!is_end ()) {
    now_clock_ = clock ();

    // input from keybord
    action_by_input_from_keybord ();

    if (!(now_clock_ >= last_clock_ + INTERVAL_))
      continue;

    ++count;
    last_clock_ = now_clock_;
    if (10 < count) {
      count = 0;
      invader.move_invaders (screen.SCREEN_HEIGHT_, screen.SCREEN_WIDTH_);
      shoot_invader_bullet ();
      call_print_screen ();
    }
    invader_bullet_processing ();
    player_bullet_processing ();
    call_print_screen ();
  }
}

/*******************************************/
/* date: 2022/01/10                        */
/* what: look at this function             */
/*******************************************/
void space_invader::
SpaceInvader::action_by_input_from_keybord ()
{
  if (kbhit ()) {
    player.move_player (getch (), screen.SCREEN_WIDTH_);
    call_print_screen ();
  }
}

/*******************************************/
/* date: 2022/01/10                        */
/* what: shoot invader bullet by           */
/*       std::mt19937                      */
/*******************************************/
void space_invader::
SpaceInvader::shoot_invader_bullet ()
{
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  auto invader_array = invader.get_invader_array ();
  // search top alive invader
  for (int i = 0; i < invader.INVADER_COLUMN_; ++i) {
    if (engine () % (invader.INVADER_COLUMN_ / 2))
      continue;
    int top_invader_row = -1;
    for (int j = 0; j < invader.INVADER_ROW_; ++j) {
      if (!invader_array.at(j).at(i).is_dead_)
        top_invader_row = j;
    }
    if (0 > top_invader_row)
      continue ;
    invader.invader_bullet_.shoot_bullet (
        i,
        top_invader_row,
        invader_array.at(top_invader_row).at(i).x_,
        invader_array.at(top_invader_row).at(i).y_);
  }
}

/*******************************************/
/* date: 2022/01/11                        */
/* what: look at this function name        */
/*******************************************/
bool space_invader::SpaceInvader::is_end ()
{
  return lose_flag || is_clear ();
}

/*******************************************/
/* date: 2022/01/11                        */
/* what: look at this function name        */
/*******************************************/
bool space_invader::
SpaceInvader::is_clear ()
{
  return kill_invader_count == 
    invader.INVADER_ROW_ * invader.INVADER_COLUMN_;
}
