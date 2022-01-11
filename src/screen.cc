#include "screen.hpp"

/******************************************/
/* date: 2022/01/10                       */
/* what: Screen constructor               */
/*       set size secreen_array_          */
/******************************************/
space_invader::Screen::Screen ()
{
  screen_array_.resize (SCREEN_HEIGHT_);
  for (int i = 0; i < SCREEN_HEIGHT_; ++i)
    screen_array_.at(i).resize (SCREEN_WIDTH_);
}

/******************************************/
/* date: 2022/01/10                       */
/* what: print screen                     */
/*       operate screen_array_            */
/******************************************/
void space_invader::Screen::print_screen (
    space_invader::Invader invader,
    space_invader::Player player)
{
  screen_to_zero ();
  set_screen (invader, player);
  clear_console ();
  for (int i = 0; i < SCREEN_HEIGHT_; ++i) {
    for (int j = 0; j < SCREEN_WIDTH_; ++j) {
      printf ("%s", MARKER_[screen_array_.at(i).at(j)].c_str ());
    }
    printf ("\n");
  }
}

/******************************************/
/* date: 2022/01/10                       */
/* what: format screen_array_ to zero     */
/******************************************/
void space_invader::Screen::screen_to_zero ()
{
  for (int i = 0; i < SCREEN_HEIGHT_; ++i)
    for (int j = 0; j < SCREEN_WIDTH_; ++j)
      screen_array_.at(i).at(j) = 0;
}

/******************************************/
/* date: 2022/01/10                       */
/* what: substitution invader's position  */
/*       of operate screen_array_ for     */ 
/*       invader's index                  */
/******************************************/
void space_invader::
Screen::set_invaders (space_invader::Invader invader)
{
  auto invader_array = invader.get_invader_array ();
  for (int i = 0; i < invader.INVADER_ROW_; ++i)
    for (int j = 0; j < invader.INVADER_COLUMN_; ++j)
      if (!invader_array.at(i).at(j).is_dead_)
        screen_array_.at(
            invader_array.at(i).at(j).y_).at(
            invader_array.at(i).at(j).x_) = INVADER_MARKER_;
}

/******************************************/
/* date: 2022/01/10                       */
/* what: substitution player position of  */
/*       screen_array_ for                */
/*       player's index                   */
/******************************************/
void space_invader::
Screen::set_player (space_invader::Player player)
{
  auto player_point = player.get_player_point ();
  screen_array_.at(player_point.y_).at(player_point.x_) =
    PLAYER_MARKER_;
}

/******************************************/
/* date: 2022/01/10                       */
/* what: substitution                     */
/*       invader bullet position of       */
/*       screen_array_ for                */
/*       invader bullet's index.          */
/******************************************/
void space_invader::
Screen::set_invader_bullet (
    space_invader::Invader invader)
{
  auto bullet_status =
    invader.invader_bullet_.get_invader_bullet ();
  for (int i = 0; i < invader.INVADER_COLUMN_; ++i) {
    if (!bullet_status.at(i).is_shoot_)
      continue ;
    screen_array_.at(bullet_status.at(i).y_).at(bullet_status.at(i).x_) =
      INVADER_BULLET_MARKER_;
  }
}

/******************************************/
/* date: 2022/01/10                       */
/* what: substitution                     */
/*       player_bullet position of        */
/*       screen_array_ for                */
/*       player_bullet's index            */
/******************************************/
void space_invader::
Screen::set_player_bullet (space_invader::PlayerBullet player_bullet)
{
  auto bullet_status = player_bullet.get_player_bullet_status ();
  if (!bullet_status.is_shoot_)
    return ;

  screen_array_.at(bullet_status.y_).at(bullet_status.x_) =
    PLAYER_BULLET_MARKER_;
}

/******************************************/
/* date: 2022/01/10                       */
/* what: clear output environment         */
/******************************************/
void space_invader::Screen::clear_console ()
{
#ifdef _WINDOWS
    std::system ("cls");
#else
    std::system ("clear");
#endif
}

/******************************************/
/* date: 2022/01/10                       */
/* what: call function for prepare        */
/*       screen_array_ for output to      */
/*       terminal                         */
/******************************************/
void space_invader::Screen::set_screen (
    space_invader::Invader invader,
    space_invader::Player  player)
{
  set_invaders (invader);
  set_invader_bullet (invader);
  set_player_bullet (player.player_bullet);
  set_player (player);
}
