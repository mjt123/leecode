#include "common/headers.h"
struct IDMParameter {
  double v0;         // Free flow speed
  double kethe = 4;  // free acceleration exponent
  double a = 1.4;    // maximum acceleration
  double b = 2;      // desired deceleration
  double c = 0.99;   // coolness factor
};
double CalculateAcceleration_IDM(IDMParameter* config, double s_star,
                                 double ego_speed, double front_distance) {
  double a_idm =
    config->a *
    (1 - pow(ego_speed * 3.6 / config->v0, config->kethe) -
     pow(s_star / front_distance, 3) / fabs(s_star / front_distance));
  // a_idm过小会导致之后的计算有nan
  a_idm = std::max(a_idm, -3000.0);
  if (std::isnan(a_idm) || std::isinf(a_idm)) {
    a_idm = 0;
  };
  return a_idm;
}
double CalculateSstar_TargetSpacing(IDMParameter* config,
                                    const double target_spacing,
                                    const double old_target_speed,
                                    const double ego_speed,
                                    const double relative_speed) {
  //速度系数speed_k，根据旧的期望速度和v0比值求得。暂命此名
  double speed_k =
    pow(1 - pow((old_target_speed * 3.6 / config->v0), config->kethe), 0.5);
  if (std::isnan(speed_k) || std::isinf(speed_k)) speed_k = 0;
  double s_star =
    (target_spacing) * speed_k +
    ego_speed * relative_speed / (2 * sqrt(config->a * config->b));
  return s_star;
}
double CalculateSstar_TimeGap(IDMParameter* config, const double s0,
                              const double time_gap, const double ego_speed,
                              const double relative_speed) {
  double headway_distance = s0 + ego_speed * time_gap;  //车头时距对应距离
  double s_star = headway_distance + ego_speed * relative_speed /
                  (2 * sqrt(config->a * config->b));
  return s_star;
}
int main() {
  double relative_speed = -0.7;
  double ego_speed = 0.7;
  IDMParameter idm_parameter;
  idm_parameter.a = 1.4;
  idm_parameter.b = 2;
  idm_parameter.c = 0.99;
//  idm_parameter.v0 = (ego_speed +
//                      relative_speed) *
//                     3.6 +
//                     10;
  idm_parameter.v0 = 120;
  idm_parameter.kethe = 4;

  double target_spacing = 1 + 1.55 * ego_speed;
//  double target_spacing = 8 + 1.55 * min(ego_speed, ego_speed + relative_speed);
  double relative_distance = 5;

  double s_star = CalculateSstar_TargetSpacing(
                    &idm_parameter, target_spacing, ego_speed, ego_speed,
                    -std::max(relative_speed, -ego_speed));
//  double s_star2 = CalculateSstar_TimeGap(&idm_parameter, 2, 1.55, ego_speed, -std::max(relative_speed, -ego_speed));
//  cout << s_star << " " << s_star2 << endl;
  double  safe_acceleration = CalculateAcceleration_IDM(
                                &idm_parameter, s_star, ego_speed, relative_distance);
  cout << safe_acceleration << endl;
}
//int main() {
//  return 0;
//}
