set(sources
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_bc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_boundary.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_dirichlet.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_dmap.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_fd.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_grid.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_io.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_metric.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_neumann.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_operator.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_solver.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_mat.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_pc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_stencil.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_signals.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_classify.c
  ${CMAKE_CURRENT_SOURCE_DIR}/stella_util.c)

if (ENABLE_CEDAR)
  list(APPEND sources ${CMAKE_CURRENT_SOURCE_DIR}/stella_cedar.c)
endif()

set(stella_sources ${sources} PARENT_SCOPE)
