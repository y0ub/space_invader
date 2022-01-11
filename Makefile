cc_version     = -std=c++17
degug_options  = -Wall -g
release_option = -O3
release_object_dir = bin/release/object/
release_objects        = bin/release/object/space_invader.o bin/release/object/screen.o bin/release/object/invader.o\
								 bin/release/object/invader_bullet.o bin/release/object/player.o bin/release/object/player_bullet.o

release:
	clang++ -c -o $(release_object_dir)space_invader.o src/space_invader.cc $(cc_version) $(release_options)
	clang++ -c -o $(release_object_dir)screen.o src/screen.cc $(cc_version) $(release_options)
	clang++ -c -o $(release_object_dir)invader.o src/invader.cc $(cc_version) $(release_option_options)
	clang++ -c -o $(release_object_dir)invader_bullet.o src/invader_bullet.cc $(cc_version) $(release_options)
	clang++ -c -o $(release_object_dir)player.o src/player.cc $(cc_version) $(release_options)
	clang++ -c -o $(release_object_dir)player_bullet.o src/player_bullet.cc $(cc_version) $(release_options)
	clang++ -o bin/release/space_invader $(release_objects) src/main.cc $(cc_version) $(release_options)

run:
	./bin/release/space_invader

debug:bin/space_invader.o bin/screen.o bin/invader.o bin/player.o bin/player_bullet.o bin/invader_bullet.o
	clang++ -o bin/$@ src/main.cc $^ $(cc_version) $(degug_options)

debug_objects:
	clang++ -c -o bin/space_invader.o src/space_invader.cc $(cc_version) $(degug_options)
	clang++ -c -o bin/screen.o src/screen.cc $(cc_version) $(degug_options)
	clang++ -c -o bin/invader.o src/invader.cc $(cc_version) $(degug_options)
	clang++ -c -o bin/invader_bullet.o src/invader_bullet.cc $(cc_version) $(degug_options)
	clang++ -c -o bin/player.o src/player.cc $(cc_version) $(degug_options)
	clang++ -c -o bin/player_bullet.o src/player_bullet.cc $(cc_version) $(degug_options)

debug_run:
	./bin/debug
