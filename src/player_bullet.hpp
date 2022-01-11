#ifndef SPACE_INVADER_SRC_PLAYER_BULLET_HPP
#define SPACE_INVADER_SRC_PLAYER_BULLET_HPP

namespace space_invader
{
  class PlayerBullet
  {
    private:
      struct BulletStatus
      {
        int x_;
        int y_;
        bool is_shoot_;
      };

      // value
      BulletStatus bullet_status;
      
      // function
      void set_player_bullet_status ();

    public:
      // function
      space_invader::PlayerBullet::BulletStatus get_player_bullet_status ();
      void shoot_bullet (const int x, const int y);
      void move_bullet ();
      void delete_bullet ();
  };
} // namespace space_invader

#endif
