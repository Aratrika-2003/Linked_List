//to create a music player

#include<stdio.h>
#include<stdlib.h>
#define ITEM char
typedef struct st
{
    ITEM data;
    struct st *prev;
    struct st *next;
}music;

music* create(ITEM song)
{
	music* new_track = (music*)malloc(sizeof(music));
	
	new_track->data = song;
	new_track->next = NULL;
	new_track->prev = NULL;
	
	return new_track;
}
/*S.Start the player*/
void start(music* track)
{
    ITEM song;
    music* start = create(song);
}
music* search_by_pos(music* head_track,int pos)//to search a song by position
{
    int i, c = 0;
    if(head_track == NULL)
    {
        printf("\nThe linked list is empty ");
        return NULL;
    }
    if(pos < 0)
    {
        printf("\nInvalid position ");
        return NULL;
    }
    while(head_track != NULL)
    {
        head_track = head_track->next;
        c++;
    }
    for(i = 0; i < pos - 1; i++)
    {
        head_track = head_track->next;
    }

    if(pos > c)
    {
        printf("\nInvalid position ");
        return NULL;
    }

    return head_track;
}
/*J.Jump to a specific track*/
music* jump(music* head_track,int pos)
{
    music* song;

    while(head_track != NULL)
    {
        song = search_by_pos(head_track,pos);
    }

    return song;
}
/*F.First track*/
void first_track(music* first)
{
    while(first != NULL)
    {
        printf("%c ",first->data);
        first = first->next;
    }
    printf("\n");
}
/*L.Last track*/
void last_track(music* last)
{
    while(last != NULL)
    {
        printf("%c ",last->data);
        last = last->prev;
    }
    printf("\n");
}

/*A.add a track after an  existing track*/
void add_track_after(music* pos,ITEM song)
{
    music* temp;
    temp = create(song);

    temp->prev = pos;
    temp->next = pos->next;
    pos->prev->next = temp;
    pos->next = temp;
}
/*B.add a track before an existing track*/
void add_track_bef(music* pos,ITEM song)
{
    music* temp = create(song);

    temp->next = pos;
    temp->prev = pos->prev;
    pos->next->prev = temp;
    pos->prev = temp;
}
/*R.remove a specific track from the playlist*/
void del_any_track(music* track)
{
    track->prev->next = track->next;
    track->next->prev = track->prev;
    free(track);
}

/*void sort_track(music** head)
{
    music* curr = *head;
    music* temp;
    music* ncurr = curr->next;
}*/

/*N.Next track*/
void next_track(music* first_track)
{
    if(first_track == NULL)
        return;

    while(first_track != NULL)
    {
        first_track = first_track->next;
        printf("%c ",first_track->data);
    }
}

/*P.Previous track*/
void prev_track(music* last_track)
{
    if(last_track == NULL)
        return;

    while(last_track != NULL)
    {
        last_track = last_track->prev;
        printf("%c ",last_track->data);
    }
}