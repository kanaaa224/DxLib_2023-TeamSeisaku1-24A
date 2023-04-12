/********************************
* �����L���O���
********************************/
void DrawRanking(void) {

    // �X�y�[�X�L�[�Ń��j���[�ɖ߂�
    if (gKeyFlg & PAD_INPUT_M) gGameMode = TITLE;

    // �����L���O��ʕ\��
    DrawGraph(0, 0, gRankingImg, FALSE);

    // �����L���O�ꗗ��\��
    SetFontSize(18);
    for (int i = 0; i < RANKING_DATA; i++) {
        DrawFormatString(50, 170 + i * 25, 0xffffff, "%2d %-10s %10d", gRanking[i].no, gRanking[i].name, gRanking[i].score);
    };

    DrawString(100, 450, "--- �X�y�[�X�L�[�������ă^�C�g���֖߂� ---", 0xff0000, 0);
};

/********************************
* �����L���O���͏���
********************************/
void InputName(void) {

    // �����L���O�摜�\��
    DrawGraph(0, 0, gTitleImg, FALSE);

    // �t�H���g�T�C�Y�̐ݒ�
    SetFontSize(20);

    // ���O���͎w��������̕`��
    DrawString(150, 240, "�����L���O�ɓo�^���܂�", 0xFFFFFF);
    DrawString(150, 270, "���O���p���œ��͂��Ă�������", 0xFFFFFF);

    // ���O����
    DrawString(150, 310, "> ", 0xFFFFFF);
    DrawBox(160, 305, 300, 335, 0x000055, TRUE);
    if (KeyInputSingleCharString(170, 310, 10, gRanking[RANKING_DATA - 1].name, FALSE) == 1) {
        gRanking[RANKING_DATA - 1].score = gScore; // �����L���O�f�[�^�ɃX�R�A�o�^
        SortRanking(); // �����L���O���ёւ�
        SaveRanking(); // �����L���O�ۑ�
        gGameMode = RANKING; // �Q�[�����[�h�ύX
    };
    //gGameMode = TITLE;
};

/********************************
* �����L���O���ёւ�
********************************/
void SortRanking(void) {
    int i, j;
    RankingData work;

    // �I��@�\�[�g
    for (i = 0; i < RANKING_DATA - 1; i++) {
        for (j = i + 1; j < RANKING_DATA; j++) {
            if (gRanking[i].score <= gRanking[j].score) {
                work = gRanking[i];
                gRanking[i] = gRanking[j];
                gRanking[j] = work;
            };
        };
    };

    // ���ʕt��
    for (i = 0; i < RANKING_DATA; i++) {
        gRanking[i].no = 1;
    };
    // ���_�������ꍇ�͓������ʂƂ���
    // �����ʂ��������ꍇ�̎��̏��ʂ̓f�[�^�������Z���ꂽ���ʂƂ���
    for (i = 0; i < RANKING_DATA - 1; i++) {
        for (j = i + 1; j < RANKING_DATA; j++) {
            if (gRanking[i].score > gRanking[j].score) {
                gRanking[j].no++;
            };
        };
    };
};

/********************************
* �����L���O�ۑ�
********************************/
int SaveRanking(void) {
    FILE* fp;
#pragma warning(disable:4996)

    // �t�@�C���I�[�v��
    if ((fp = fopen("dat/rankingdata.txt", "w")) == NULL) {
        // �G���[����
        printf("Ranking Data Error\n");
        return -1;
    };
    // �����L���O�f�[�^���z��f�[�^����������
    for (int i = 0; i < RANKING_DATA; i++) {
        fprintf(fp, "%2d %10s %10d\n", gRanking[i].no, gRanking[i].name, gRanking[i].score);
    };

    // �t�@�C���N���[�Y
    fclose(fp);
    return 0;
};

/********************************
* �����L���O�ǂݍ���
********************************/
int ReadRanking(void) {
    FILE* fp;
#pragma warningI(disable:4996)

    // �t�@�C���I�[�v��
    if ((fp = fopen("dat/rankingdata.txt", "r")) == NULL) {
        // �G���[����
        printf("Ranking Data Error\n");
        return -1;
    };
    // �����L���O�f�[�^���z��f�[�^��ǂݍ���
    for (int i = 0; i < RANKING_DATA; i++) {
        int dammy = fscanf(fp, "%2d %10s %10d", &gRanking[i].no, gRanking[i].name, &gRanking[i].score);
    };

    // �t�@�C���N���[�Y
    fclose(fp);
    return 0;
};