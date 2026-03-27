/*
  Grab N Go Mart – Premium Night-Mart Experience
  ------------------------------------------------
  This script initializes:
  1) Three.js cinematic hero scene with procedural meshes + particles.
  2) Mouse-based parallax interaction.
  3) GSAP + ScrollTrigger reveal system.
  4) Placeholder GLTFLoader hook for future AI-generated models.
*/

(() => {
  const yearElement = document.getElementById("year");
  if (yearElement) {
    yearElement.textContent = new Date().getFullYear();
  }

  const stage = document.getElementById("webgl-stage");
  if (!stage || !window.THREE) return;

  // -------------------------------
  // Core scene setup
  // -------------------------------
  const scene = new THREE.Scene();
  scene.fog = new THREE.FogExp2(0x070b14, 0.06);

  const camera = new THREE.PerspectiveCamera(
    58,
    window.innerWidth / window.innerHeight,
    0.1,
    120
  );
  camera.position.set(0, 0.4, 10);

  const renderer = new THREE.WebGLRenderer({ antialias: true, alpha: true });
  renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
  renderer.setSize(window.innerWidth, window.innerHeight);
  renderer.outputColorSpace = THREE.SRGBColorSpace;
  stage.appendChild(renderer.domElement);

  // -------------------------------
  // Premium cinematic lighting
  // -------------------------------
  const ambient = new THREE.AmbientLight(0x465078, 0.65);
  scene.add(ambient);

  const neonGreenLight = new THREE.PointLight(0x00f5a0, 1.4, 40, 2.1);
  neonGreenLight.position.set(-5, 3.5, 4);
  scene.add(neonGreenLight);

  const deepPurpleLight = new THREE.PointLight(0x8b5cf6, 1.6, 38, 1.9);
  deepPurpleLight.position.set(5, -2.8, 3.2);
  scene.add(deepPurpleLight);

  const rimLight = new THREE.DirectionalLight(0xb5c9ff, 0.42);
  rimLight.position.set(0, 4, 8);
  scene.add(rimLight);

  // -------------------------------
  // Procedural premium geometry set
  // -------------------------------
  const heroGroup = new THREE.Group();
  scene.add(heroGroup);

  // Metallic torus – abstract "energy ring"
  const torus = new THREE.Mesh(
    new THREE.TorusGeometry(2.6, 0.26, 32, 120),
    new THREE.MeshPhysicalMaterial({
      color: 0x6b8cff,
      metalness: 0.92,
      roughness: 0.12,
      clearcoat: 1,
      clearcoatRoughness: 0.1,
      emissive: 0x231344,
      emissiveIntensity: 0.4
    })
  );
  torus.position.set(-1.3, 0.8, 0);
  torus.rotation.x = 0.55;
  torus.rotation.y = 0.28;
  heroGroup.add(torus);

  // Crystalline icosahedron – premium focal object
  const ico = new THREE.Mesh(
    new THREE.IcosahedronGeometry(1.2, 1),
    new THREE.MeshStandardMaterial({
      color: 0x5c7cff,
      metalness: 0.38,
      roughness: 0.25,
      emissive: 0x1f2b72,
      emissiveIntensity: 0.45,
      flatShading: true
    })
  );
  ico.position.set(2.2, -0.4, 0.9);
  heroGroup.add(ico);

  // Glass-like sphere – futuristic liquid core
  const sphere = new THREE.Mesh(
    new THREE.SphereGeometry(1.15, 64, 64),
    new THREE.MeshPhysicalMaterial({
      color: 0xa9d8ff,
      transmission: 0.88,
      opacity: 0.98,
      transparent: true,
      roughness: 0.03,
      metalness: 0.08,
      ior: 1.45,
      thickness: 0.55,
      clearcoat: 1,
      clearcoatRoughness: 0.05
    })
  );
  sphere.position.set(0.5, -1.45, -0.7);
  heroGroup.add(sphere);

  // Neon pseudo-sign text (3D box letter blocks as placeholder aesthetic)
  const signGroup = new THREE.Group();
  signGroup.position.set(0, 2.25, -1.2);
  heroGroup.add(signGroup);

  const signMat = new THREE.MeshStandardMaterial({
    color: 0x0b0f19,
    emissive: 0x00f5a0,
    emissiveIntensity: 1,
    metalness: 0.2,
    roughness: 0.5
  });

  const glyphs = [-2.1, -1.4, -0.7, 0, 0.7, 1.4, 2.1];
  glyphs.forEach((x, idx) => {
    const block = new THREE.Mesh(new THREE.BoxGeometry(0.44, 0.28 + idx * 0.02, 0.16), signMat);
    block.position.x = x;
    block.position.y = Math.sin(idx) * 0.1;
    signGroup.add(block);
  });

  // -------------------------------
  // Floating dust / spark particle field
  // -------------------------------
  const particleCount = 1400;
  const particleGeometry = new THREE.BufferGeometry();
  const particlePositions = new Float32Array(particleCount * 3);

  for (let i = 0; i < particleCount; i += 1) {
    const i3 = i * 3;
    particlePositions[i3] = (Math.random() - 0.5) * 30;
    particlePositions[i3 + 1] = (Math.random() - 0.5) * 16;
    particlePositions[i3 + 2] = (Math.random() - 0.5) * 24;
  }

  particleGeometry.setAttribute("position", new THREE.BufferAttribute(particlePositions, 3));

  const particles = new THREE.Points(
    particleGeometry,
    new THREE.PointsMaterial({
      color: 0xa7b8ff,
      size: 0.03,
      sizeAttenuation: true,
      transparent: true,
      opacity: 0.72,
      blending: THREE.AdditiveBlending,
      depthWrite: false
    })
  );
  scene.add(particles);

  // -------------------------------
  // Placeholder GLTF model integration
  // -------------------------------
  if (window.THREE && THREE.GLTFLoader) {
    const loader = new THREE.GLTFLoader();

    // Example for future drop-in model path:
    // loader.load("./models/grab-n-go-sign.glb", (gltf) => {
    //   const model = gltf.scene;
    //   model.position.set(0, -1.0, 0.5);
    //   model.scale.setScalar(1.3);
    //   heroGroup.add(model);
    // });

    // Placeholder noop to show loader is wired and ready.
    void loader;
  }

  // -------------------------------
  // Mouse parallax controls
  // -------------------------------
  const pointer = { x: 0, y: 0 };
  const targetRotation = { x: 0, y: 0 };

  window.addEventListener("pointermove", (event) => {
    pointer.x = (event.clientX / window.innerWidth) * 2 - 1;
    pointer.y = (event.clientY / window.innerHeight) * 2 - 1;
    targetRotation.y = pointer.x * 0.28;
    targetRotation.x = pointer.y * 0.18;
  });

  // -------------------------------
  // Animate scene
  // -------------------------------
  const clock = new THREE.Clock();

  const tick = () => {
    const elapsed = clock.getElapsedTime();

    // Core mesh motion
    torus.rotation.z += 0.0026;
    torus.rotation.y += 0.0018;

    ico.rotation.x += 0.0029;
    ico.rotation.y -= 0.002;

    sphere.rotation.y += 0.0024;
    sphere.position.y = -1.45 + Math.sin(elapsed * 1.4) * 0.2;

    // Group drift + parallax interpolation
    heroGroup.rotation.x += (targetRotation.x - heroGroup.rotation.x) * 0.03;
    heroGroup.rotation.y += (targetRotation.y - heroGroup.rotation.y) * 0.03;
    heroGroup.position.y = Math.sin(elapsed * 0.6) * 0.22;

    // Subtle light breathing
    neonGreenLight.intensity = 1.25 + Math.sin(elapsed * 2.2) * 0.18;
    deepPurpleLight.intensity = 1.45 + Math.cos(elapsed * 1.8) * 0.15;

    // Particle drift
    particles.rotation.y += 0.0006;
    particles.rotation.x = Math.sin(elapsed * 0.15) * 0.03;

    renderer.render(scene, camera);
    requestAnimationFrame(tick);
  };

  tick();

  window.addEventListener("resize", () => {
    camera.aspect = window.innerWidth / window.innerHeight;
    camera.updateProjectionMatrix();
    renderer.setSize(window.innerWidth, window.innerHeight);
    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
  });

  // -------------------------------
  // GSAP ScrollTrigger (fluid motion)
  // -------------------------------
  if (window.gsap && window.ScrollTrigger) {
    gsap.registerPlugin(ScrollTrigger);

    gsap.utils.toArray(".reveal").forEach((element, index) => {
      gsap.fromTo(
        element,
        {
          y: 40,
          opacity: 0,
          filter: "blur(8px)"
        },
        {
          y: 0,
          opacity: 1,
          filter: "blur(0px)",
          duration: 0.95,
          ease: "power3.out",
          delay: Math.min(index * 0.03, 0.24),
          scrollTrigger: {
            trigger: element,
            start: "top 86%",
            toggleActions: "play none none reverse"
          }
        }
      );
    });

    // Hero copy entrance timeline
    const heroTimeline = gsap.timeline({ defaults: { ease: "power3.out" } });
    heroTimeline
      .from(".hero-copy .eyebrow", { y: 22, opacity: 0, duration: 0.65 })
      .from(".hero-copy h1", { y: 34, opacity: 0, duration: 0.75 }, "-=0.35")
      .from(".hero-copy .lead", { y: 22, opacity: 0, duration: 0.65 }, "-=0.45")
      .from(".hero-copy .hero-actions .btn", { y: 18, opacity: 0, stagger: 0.08, duration: 0.55 }, "-=0.35");
  }
})();
