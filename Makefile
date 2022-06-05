all : exec

main.o : main.c continue_playing.h display_best_score.h displays_the_player_table.h initialisation_2.h initialisation_tab_player_2.h initialisation_tab_player.h initialisation.h length_int.h play_2.h play.h protect_bug.h revelation_of_the_squares.h verification.h victory_animation.h victory_verification.h
    gcc -c main.c -o main.o

exec : main.o
    gcc $^ -o $@

clean : 
    rm *.o
    rm exec
