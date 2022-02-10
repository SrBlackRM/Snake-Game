int points_init(){
    point.point_size = 30;
    point.point_rect_dest.x = rand()%(WIDTH-point.point_size);
    point.point_rect_dest.y = rand()%(HEIGHT-point.point_size);

    point.point_rect_src.x = 0;
    point.point_rect_src.y = 0;
    point.point_rect_src.w = point.point_size;
    point.point_rect_src.h = point.point_size;

    point.point_rect_dest.x = point.point_rect_dest.x;
    point.point_rect_dest.y = point.point_rect_dest.y;
    point.point_rect_dest.w = point.point_size;
    point.point_rect_dest.h = point.point_size;


    return 1;
}
