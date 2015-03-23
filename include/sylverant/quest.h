/*
    This file is part of Sylverant PSO Server.

    Copyright (C) 2009, 2011, 2014, 2015 Lawrence Sebald

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License version 3
    as published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QUEST_H
#define QUEST_H

#include <inttypes.h>

#define SYLVERANT_QUEST_V1  (1 << 0)
#define SYLVERANT_QUEST_V2  (1 << 1)
#define SYLVERANT_QUEST_GC  (1 << 2)
#define SYLVERANT_QUEST_BB  (1 << 3)

#define SYLVERANT_QUEST_NORMAL      (1 << 0)
#define SYLVERANT_QUEST_BATTLE      (1 << 1)
#define SYLVERANT_QUEST_CHALLENGE   (1 << 2)
#define SYLVERANT_QUEST_GOVERNMENT  (1 << 3)

#define SYLVERANT_QUEST_BINDAT      0
#define SYLVERANT_QUEST_QST         1
#define SYLVERANT_QUEST_UBINDAT     2

#define SYLVERANT_QUEST_ENDROP_NONE     0
#define SYLVERANT_QUEST_ENDROP_NORARE   1
#define SYLVERANT_QUEST_ENDROP_PARTIAL  2
#define SYLVERANT_QUEST_ENDROP_FREE     3

#define SYLVERANT_QUEST_EP1             (1 << 0)
#define SYLVERANT_QUEST_EP2             (1 << 1)
#define SYLVERANT_QUEST_EP4             (1 << 2)

struct sylverant_quest_enemy {
    uint32_t key;
    uint32_t value;
};

typedef struct sylverant_quest {
    uint32_t qid;
    uint32_t versions;

    char name[32];
    char desc[112];

    char *long_desc;
    char *prefix;
    void *user_data;

    int episode;
    int event;
    int format;
    int max_players;
    int min_players;

    /* Stuff related to server-side drops. */
    int num_monster_types;
    int num_monster_ids;
    struct sylverant_quest_enemy *monster_types;
    struct sylverant_quest_enemy *monster_ids;

    int sync;
} sylverant_quest_t;

typedef struct sylverant_qcat {
    char name[32];
    char desc[112];

    uint32_t type;
    uint32_t episodes;
    int quest_count;
    sylverant_quest_t *quests;
} sylverant_quest_category_t;

typedef struct sylverant_qlist {
    sylverant_quest_category_t *cats;
    int cat_count;
} sylverant_quest_list_t;

extern int sylverant_quests_read(const char *filename,
                                 sylverant_quest_list_t *rv);

extern void sylverant_quests_destroy(sylverant_quest_list_t *list);

#endif /* !QUEST_H */
